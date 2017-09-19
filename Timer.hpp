#include <SFML/System.hpp>

#ifndef TIMER_HPP
#define TIMER_HPP


//if clock == wantedTime -> return true

class Timer { //counts down in milliseconds and returns true when finished

public:
    Timer ( void ); //1s default timer, use if we plan on only using a few times
    Timer ( unsigned int ); //specified timer, use if we will wait multiple times the same amount
    ~Timer (void); //does nothing

    bool start ( void ); //starts counting with value stored as endTimer
    bool start ( unsigned int ); //starts counting with value stored inside parameter
    void setTimer ( unsigned int ); //sets endTimer
    unsigned int getTime ( void ); //returns current time elapsed

private:
    sf::Clock Counter;
    unsigned int endTimer;

};


#endif
