#ifndef PRESSBUTTON_HPP
#define PRESSBUTTON_HPP
#include <windows.h>
#include <stdexcept>
#include <iostream>

// https://msdn.microsoft.com/en-us/library/windows/desktop/ms646293%28v=vs.85%29.aspx?f=255&MSPPError=-2147217396
//is key pressed

//virtualKey codes
//https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx


class ButtonPress {

public:
    //initialization functions
    ButtonPress ( void );
    ButtonPress ( unsigned int );
    void setKey ( unsigned int );
    unsigned int getKey ( void );

    //starts, ends and detects a keypress/unpress (idfk how to just do that with a "click" that'd be nice)
    void startPress ( void );
    void endPress ( void );
    bool getPressStatus( void );


private:
    //which key this ButtonPress object will work with, usually your PTT key
    unsigned int Key;


};

#endif
