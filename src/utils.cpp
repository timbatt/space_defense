#include <iostream>
#include <fstream>
#include "utils.hpp"


json read_json_file(const char* path) {
    std::ifstream fileStream(path);

    if (!fileStream.is_open()) {
        std::cerr << "Could not open file: " << path << std::endl;
    }

    json parsed = json::parse(fileStream);
    return parsed;
}
