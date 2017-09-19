#include "Timer.hpp"

Timer::Timer ( void ){
    setTimer(1000); //default value wait 1s
}

Timer::Timer (unsigned int wantedTime ){
    setTimer(wantedTime);
}

void Timer::setTimer (unsigned int wantedTime){
        endTimer=wantedTime;
}

unsigned int Timer::getTime( void ){
    return endTimer;
}

bool Timer::start(unsigned int newTime){ //does not modify the timer stored in the class
    Counter.restart();
    while (Counter.getElapsedTime().asMilliseconds() < newTime){
        //wait patiently
    }
    return true;
}

bool Timer::start( void ){
    Counter.restart();
    while (Counter.getElapsedTime().asMilliseconds() < getTime()){
        //wait patiently
    }
    return true;
}

Timer::~Timer (void){
    //nothing, really.
};
