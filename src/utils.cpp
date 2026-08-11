#include <iostream>
#include <fstream>
#include "utils.hpp"


json read_json_file(std::string path) {
    std::ifstream fileStream(path);

    if (!fileStream.is_open()) {
        std::cerr << "Could not open file: " << path << std::endl;
    }

    json parsed = json::parse(fileStream);
    return parsed;
}


void print_memory_usage() {
    FILE* fp = fopen("/proc/self/status", "r");
    if (!fp) return;

    char line[128];
    while (fgets(line, sizeof(line), fp)) {
        // VmRSS tracks the actual physical RAM in use
        if (strncmp(line, "VmRSS:", 6) == 0) {
            std::cout << line;
            break;
        }
    }
    fclose(fp);
}

