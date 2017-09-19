//SoundBufferReader.cpp
#include "SoundBufferReader.hpp"
#include <iostream>
#include <cmath>
#include <vector>



SoundBufferReader::SoundBufferReader(void) : buttonFlag(false), toggleMute(false), sf::SoundBufferRecorder::SoundBufferRecorder(){


    setKey( 0xC0, pttKey ); //default ~ key
    setKey( 0x74, pauseKey ); //default f5 key

}

void SoundBufferReader::start( void ){
    SoundBufferRecorder::start();
    graceTimer.restart();
}


SoundBufferReader::~SoundBufferReader(void){
    stop();
}


void SoundBufferReader::setKey (unsigned int requestedKey, ButtonPress &currentButton){

    currentButton.setKey(requestedKey);

}

bool SoundBufferReader::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount){


    //for key codes https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx

    checkMute(0x74); //if muted

    if (toggleMute==false){

        for (unsigned int i=0; i<sampleCount; i++){

            if ( ( ( abs(samples[i] ) ) > soundThreshold )  && (buttonFlag==false) ) { // if sound is louder than x, press button, do not repress for the rest of sample analysis

                pttKey.startPress();
                graceTimer.restart();
                buttonFlag=!buttonFlag;

            }

            if ( ( ( abs(samples[i] ) ) > soundThreshold )  && (buttonFlag==true) ) { //if button is already pressed, just restart timer

                graceTimer.restart();

            }

        }

        if ( (graceTimer.getElapsedTime().asMilliseconds() > 500 ) && (buttonFlag==true)){ //if 500ms have passed since button has been pressed for the last time; turn off

            pttKey.endPress( );
            buttonFlag=false;
        }

    }

    return true;

}



void SoundBufferReader::checkMute(unsigned int){


    if (pauseKey.getPressStatus( ) && toggleMute==false){

        toggleMute=!toggleMute;
        std::cout<<"Microphone muted.\n\a";

    }


    else if (pauseKey.getPressStatus( ) && toggleMute==true){

        toggleMute=!toggleMute;
        std::cout<<"Microphone un-muted.\n\a\a";

    }

}



void SoundBufferReader::setThreshold (unsigned int value){
    soundThreshold=value;
}


void SoundBufferReader::calibrate (unsigned int calTime){ //calibration lenght

    sf::SoundBuffer recorder;
    sf::SoundBufferRecorder calibrator;
    calibrator.setDevice(calibrator.getDefaultDevice());
    calibrator.start();
    Timer calibrationTime;
    calibrationTime.start(4000);
    calibrator.stop();
    recorder=calibrator.getBuffer();

    double tempCalibratedGain=0.0;
    unsigned int calibratedGain=0; // gain to be used to activate PTT
    const sf::Int16* samples=recorder.getSamples();
    std::vector <double> unsignedSamples;

    for (unsigned int i=0; i < recorder.getSampleCount(); i++){ //if gain is greater than 1000, accept value
        if ( (abs( samples[i] ) )  > 1500){
            unsignedSamples.push_back(abs(samples[i]));
        }
    }

    for (unsigned int i=0; i<unsignedSamples.size(); i++){ //get average gain for acceptable values
            tempCalibratedGain+= unsignedSamples[i]/(unsignedSamples.size());
    }

    calibratedGain=1.25*tempCalibratedGain;

    if (calibratedGain < 1000){ //if gain was not detected, re-calibrate
        return calibrate(calTime);
    }

    setThreshold(calibratedGain);

}
