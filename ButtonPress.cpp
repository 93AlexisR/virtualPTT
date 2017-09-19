#include "ButtonPress.hpp"


ButtonPress::ButtonPress ( void ) : Key(0x07){
   //default key is tilde
}

ButtonPress::ButtonPress(unsigned int newKey){
    setKey(newKey);
}

void ButtonPress::setKey(unsigned int newKey){


    if (newKey > 0 && newKey < 0xFE){
        Key=newKey;
    }

    else{
        throw std::invalid_argument("Key specified is out of bounds");
    }


}

unsigned int ButtonPress::getKey( void ){
    return Key;
}


bool ButtonPress::getPressStatus( void ){

    if( GetAsyncKeyState( getKey() ) & 0x8000 )
    {
        return true;
    }
    return false;
}


void ButtonPress::startPress( void ){
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    //pressing specified key
    ip.ki.wVk = getKey(); // virtual-key code for selected key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

}


void ButtonPress::endPress( void ){ //

    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = getKey(); // virtual-key code for selected key

    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));

}
