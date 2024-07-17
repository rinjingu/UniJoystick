#include "joystick_util.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <stdio.h>
#include <nlohmann/json.hpp>


#include "joystick_util.h"
#include "joystick_remap.h"
joystick::JoystickConfig joystick::util::read_config(std::string path)
{
    std::cout << "Reading config from " << path << std::endl;

    using json = nlohmann::json;

    std::fstream f(path);
    if (!check_config(f))
    {
        // replace the file with the default config
        f.open(path, std::ios::out);
        f << DefaultConfig.dump();
    }
    json config = json::parse(f);

    JoystickConfig joystick_config(config["name"], config["joystick_type"], config["mapping"]);
    return joystick_config;
}

void joystick::util::event_mapping()
{
}

bool joystick::util::check_config(std::fstream &config)
{
    // Check if config file exists
    if (!config.is_open())
    {
        return false;
    }

    // Check if config file is empty
    if (config.peek() == std::ifstream::traits_type::eof())
    {
        return false;
    }
    return true;
}