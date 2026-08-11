#include <iostream>
#include "Settings.hpp"


const char* Settings::SETTINGS_PATH = "settings.json";

const char* Settings::NAME = "Tower Defense";
int Settings::FRAME_RATE = 60;
int Settings::WINDOW_H = 800;
int Settings::WINDOW_W = 1200;
int Settings::MAX_ENTITY_PER_TYPE = 128;
int Settings::MAX_PARTICLE_COUNT = 1024;
json Settings::JSON = json::parse("{}");


void Settings::init() {
    std::cout << "INIT SETTINGS" << std::endl;
    
    Settings::JSON = read_json_file(Settings::SETTINGS_PATH);
    
    
    Settings::FRAME_RATE = Settings::JSON.at("FRAME_RATE");
    Settings::WINDOW_W = Settings::JSON.at("WINDOW_W");
    Settings::WINDOW_H = Settings::JSON.at("WINDOW_H");


    std::cout << "Set frame rate to " << Settings::FRAME_RATE << std::endl;;
    std::cout << "Set width to " << Settings::WINDOW_W << std::endl;;
    std::cout << "Set height to " << Settings::WINDOW_H << std::endl;
}