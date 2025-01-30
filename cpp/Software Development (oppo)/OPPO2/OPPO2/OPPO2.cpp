// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
//#include <vld.h>
#include "Color.h"
#include "Point.h"


using namespace std;

//обработка ошибок. при чтении из файла если программа находит ошибку (не red а: rEd, green, {empty} ... ) 
//то она выводит строку ошибки, и дальше продолжает работу, пропуская строку.сделать все через throw
//catch описан в мейне (нужно ли его еще раз описывать в другой функции -- решить) 





ifstream open_file(const string& fname)
{
	ifstream in(fname);
	if (false == in.is_open()) {
		throw std::runtime_error("file not open" + std::to_string(5));
	}
	return in;
}

int main()
{
	try {
		ifstream in = open_file("Текст.txt");
		auto points = Point::readSome(in);
		Point::printSome(points, std::cout);
	}
	catch(std::runtime_error& error_message) {
		cerr << error_message.what();
	}
	
}