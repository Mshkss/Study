// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <stdexcept>
#include <iostream>
#include "Color.h"

using namespace std;

Color string_to_color(const string& str) {
	
		if (str == "red" || str == "Red") {
			return Color::Red;
		}
		else if (str == "green" || str == "Green") {
			return Color::Green;
		}
		else if (str == "blue" || str == "Blue") {
			return Color::Blue;
		}

		throw std::runtime_error("Color error!");
}

string color_to_string(const Color c)
{
	switch (c)
	{
	case Color::Red: {
		return "red";
	}

	case Color::Blue: {
		return "blue";
	}

	case Color::Green: {
		return "green";
	}
	default:
		std::cerr << "Ошибка цвета" << std::endl;
		break;
	}

	return {};
}