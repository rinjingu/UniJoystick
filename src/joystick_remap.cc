#include "joystick_remap.h"

#include <iostream>
#include <stdexcept>

#include "joystick.hh"

namespace joystick
{

    JoystickRemapper::JoystickRemapper()
    {
        joystick = new Joystick();
    }

    JoystickRemapper::JoystickRemapper(int joystick_number)
    {
        joystick = new Joystick(joystick_number);
    }

    JoystickRemapper::JoystickRemapper(std::string device_path)
    {
        joystick = new Joystick(device_path);
    }

    JoystickRemapper::~JoystickRemapper()
    {
        delete joystick;
        delete &config;
    }

    void JoystickRemapper::event_mapping()
    {
        try
        {
            check_joystick();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        JoystickEvent event;
        if (joystick->sample(&event))
        {
            if (event.isButton())
            {
                printf("Button %u is %s\n", event.number, event.value == 0 ? "up" : "down");
            }
            else if (event.isAxis())
            {
                printf("Axis %u is at position %d\n", event.number, event.value);
            }
        }
    }

    void JoystickRemapper::set_config(JoystickConfig config)
    {
        this->config = config;
    }

    void JoystickRemapper::check_joystick()
    {
        if (joystick->isFound())
        {
            return;
        }

        throw std::runtime_error("Joystick not found");
    }

} // namespace joystick
