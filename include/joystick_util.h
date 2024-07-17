
#ifndef _JOYSTICK_UTIL_H_
#define _JOYSTICK_UTIL_H_

#include <string>
#include <nlohmann/json.hpp>
#include <joystick_mapping.h>
#include "joystick_remap.h"
namespace joystick
{
namespace util
{
    static nlohmann::json DefaultConfig = {
        {"name", "default"},
        {"joystick_type", "default"},
        {"mapping", {
                {"axis", 
                    {"X", JS_AXIS_0}, 
                    {"Y", JS_AXIS_1},
                    {"Z", JS_AXIS_2},
                    {"Pitch", JS_AXIS_3},
                    {"Yaw", JS_AXIS_4},
                    {"Roll", JS_AXIS_5},
                    {"Slider", JS_AXIS_6}
                },
                {"buttons",
                    {"Button1", JS_BUTTON_0},
                    {"Button2", JS_BUTTON_1},
                    {"Button3", JS_BUTTON_2},
                    {"Button4", JS_BUTTON_3},
                    {"Button5", JS_BUTTON_4},
                    {"Button6", JS_BUTTON_5},
                    {"Button7", JS_BUTTON_6},
                    {"Button8", JS_BUTTON_7},
                    {"Button9", JS_BUTTON_8},
                    {"Button10", JS_BUTTON_9},
                    {"Button11", JS_BUTTON_10},
                    {"Button12", JS_BUTTON_11},
                    {"Button13", JS_BUTTON_12},
                    {"Button14", JS_BUTTON_13},
                    {"Button15", JS_BUTTON_14},
                    {"Button16", JS_BUTTON_15},
                    {"Button17", JS_BUTTON_16},
                    {"Button18", JS_BUTTON_17}
                }
            }
        }
    };
    
    void event_mapping();
    bool check_config(std::fstream &config);
    JoystickConfig read_config(std::string path);

} // namespace util
} // namespace joystick


#endif