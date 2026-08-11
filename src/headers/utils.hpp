#pragma once

#include "json.hpp"

using json = nlohmann::json;

json read_json_file(std::string path);

void print_memory_usage();