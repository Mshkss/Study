// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <string>


#include "pch.h"
#include "CppUnitTest.h"


#include "../OPPO2/Color.h"
#include "../OPPO2/Point.h"
#include "../OPPO2/Point.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(tests)
	{
	public:

		TEST_METHOD(Color_String_to_color_errs)
		{
			const std::string test_cases[] = {
				"12234", "white"
			};

			for (const auto& test_case : test_cases) {
				try {
					Color color = string_to_color(test_case);
					Assert::Fail();
				}
				catch (std::exception& err) {
					std::cout << err.what();
				}
			}
		}

		TEST_METHOD(Color_String_to_color_okks)
		{
			const std::string test_cases[] = {
				"red", "blue", "green"
			};

			for (const auto& test_case : test_cases) {
				try {
					Color color = string_to_color(test_case);
				}
				catch (std::exception& err) {
					Assert::Fail();
				}
			}
		}

		////

		TEST_METHOD(Read_Point_errs) {
			const std::string test_cases[] = { "6.66 7.77 8.88 red","6.66 blue" };

			for (const auto& test_case : test_cases) {
				try {
					std::istringstream test_input(test_case);
					Point point = Point::create(test_input);
					Assert::Fail();
				}
				catch (std::exception& err) {
					std::cout << err.what();
				}
			}
		}


		TEST_METHOD(Read_Point_okks) {
			const std::string test_case = "6.66 7.77 red";

			try {
				std::istringstream test_input(test_case);
				Point point = Point::create(test_input);
			}
			catch (std::exception& err) {
				Assert::Fail();
			}
		}
	};
}