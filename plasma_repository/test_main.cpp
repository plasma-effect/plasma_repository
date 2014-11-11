#include<plasma/enum.hpp>
#include<iostream>

PLASMA_ENUM(test, a, b, c);

int main()
{
	test t{};
	t++;
	std::cout << (t == test::b) << std::endl;
	t++;
	std::cout << (t == test::c) << std::endl;
	t++;
	std::cout << (t == test::a) << std::endl;

}