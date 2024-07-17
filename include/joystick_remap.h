#ifndef _JOYSTICK_REMAP_H_
#define _JOYSTICK_REMAP_H_

#include "joystick.hh"
#include <string>
#include <joystick_mapping.h>
#include <nlohmann/json.hpp>
namespace joystick
{



class JoystickRemapper{
    public:
        std::string joystick_name;
        Joystick *joystick;
        JoystickConfig config;
        ~JoystickRemapper();
        JoystickRemapper();
        JoystickRemapper(int joystick_number);
        JoystickRemapper(std::string device_path);
        void event_mapping();
};



class JoystickConfig{
    public:
        JoystickConfig(){
            this->name = "default";
            this->joystick_type = "default";
            this->mapping = nullptr;
        }

        JoystickConfig(std::string name, std::string joystick_type, nlohmann::json mapping){
            this->name = name;
            this->joystick_type = joystick_type;
            this->mapping = mapping;
        }

        std::string get_name(){
            return this->name;
        }

        void set_name(std::string name){
            this->name = name;
        }

        std::string get_joystick_type(){
            return this->joystick_type;
        }

        void set_joystick_type(std::string joystick_type){
            this->joystick_type = joystick_type;
        }

        // get mapping by inputting the key
        nlohmann::json get_mapping(std::string key){
            return this->mapping[key];
        }

        // set mapping by inputting the key and value
        void set_mapping(std::string key, nlohmann::json value){
            this->mapping[key] = value;
        }

    private:
        std::string name;
        std::string joystick_type;
        nlohmann::json mapping;
};
}   // namespace joystick

#endif