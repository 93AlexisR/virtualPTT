#ifndef SFML_SOUNDBUFFERREADER_HPP
#define SFML_SOUNDBUFFERREADER_HPP

#include <stdexcept>
#include <SFML/Audio.hpp>
#include "Timer.hpp"
#include "ButtonPress.hpp"



class SoundBufferReader : public sf::SoundBufferRecorder
{

public:

    //initialization functions
    SoundBufferReader(void);
    ~SoundBufferReader(void);
    void start( void );
    void setKey (unsigned int, ButtonPress &button);

    //timer functions, grace timer is the period in which no sound over treshold is detected but
    //key will not be unpressed in order not to spam the keyboard stream with inputs
    void resetGrace (void); //resets grace to 0
    void setGrace (unsigned int); //sets grace time
    float getGrace (void); //returns grace time left in ms

    //check if key is already pressed
    void switchFlag(void);


    //volume activation threshold control
    void setThreshold (unsigned int);

    //calibration tools
    void calibrate ( unsigned int ); //Automatic calibration
    void calibUp ( void ); //Manual Calibration
    void calibDown ( void );


    void checkMute(unsigned int); //checks if mic muted

protected:

    virtual bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount); //set of data to be processed
    void setGrace (float);

private:

    //Keyboard press objects
    ButtonPress pttKey; //PTT key to be virtually pressed
    ButtonPress pauseKey; //Key to pause PTT operations


    void WaitMil (int); //waits a millisecond
    unsigned int soundThreshold; //Threshold of sound before PTT activation


    // Button Objects
    bool toggleMute;
    bool buttonFlag; //ensures button is not spam-clicked i.e. if true -> do not press again until unpressed

    sf::Clock graceTimer; //



};




#endif // SFML_SOUNDBUFFERREADER_HPP
