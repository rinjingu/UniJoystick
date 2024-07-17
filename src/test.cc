#include "joystick_remap.h" 

int main(int argc, char const *argv[])
{
    joystick::JoystickRemapper remapper;
    
    while (true)
    {
        remapper.event_mapping();
    }
    

    return 0;
}
