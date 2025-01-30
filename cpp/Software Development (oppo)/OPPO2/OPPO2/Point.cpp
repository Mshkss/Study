// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <iostream>

#include "Point.h"

using namespace std;


Point::Point() : a(0), b(0), colour (Color::Red) {}

Point::Point(double _a, double _b, Color _color) :
	a(_a), b(_b), colour(_color) {}

void Point::print(std::ostream& out) const
{
	out << a << " " << b << " " << color_to_string(colour) << endl;
}

Point Point::create(std::istream& in)
{
	Point test1;

	if(!(in >> test1.a >> test1.b)) throw std::runtime_error("coordinate error!");

	std::string str;
	in >> str;

	const auto color = string_to_color(str);
	test1.colour = color;
	return test1;
}

vector<Point> Point::readSome(std::istream& in) {
	vector<Point>points;


	while (!in.eof() && !cin.fail()) {
		Point test1 = Point::create(in);
		points.push_back(test1);
	}
	return points;
}

void Point::printSome(const vector<Point> points, std::ostream& out)
{
	for (int i = 0; i < points.size(); ++i) {
		points[i].print(out);
	}
}