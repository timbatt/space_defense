#pragma once

#include "json.hpp"

using json = nlohmann::json;

json read_json_file(const char* path);