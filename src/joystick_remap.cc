#include "joystick_remap.h"

#include <iostream>
#include <stdexcept>

#include "joystick.hh"

namespace joystick
{

    class JoystickRemapper
    {
    public:
        std::string joystick_name;
        Joystick *joystick;
        JoystickConfig config;
        JoystickRemapper()
        {
            joystick = new Joystick();
        }
        JoystickRemapper(int joystick_number)
        {
            joystick = new Joystick(joystick_number);
        }
        JoystickRemapper(std::string device_path)
        {
            joystick = new Joystick(device_path);
        }
        JoystickRemapper(std::string device_path, bool blocking)
        {
            joystick = new Joystick(device_path, blocking);
        }
        ~JoystickRemapper()
        {
            delete joystick;
            delete &config;
        }

        void event_mapping()
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

        void set_config(JoystickConfig config)
        {
            this->config = config;
        }

    private:
        void check_joystick()
        {
            if (joystick->isFound())
            {
                return;
            }

            throw std::runtime_error("Joystick not found");
        }
    };

} // namespace joystick
