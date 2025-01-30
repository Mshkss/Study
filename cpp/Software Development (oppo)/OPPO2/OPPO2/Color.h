// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#pragma once

#include <string>

enum class Color {
	Red, Green, Blue
};

Color string_to_color(const std::string& str);
std::string color_to_string(const Color c);