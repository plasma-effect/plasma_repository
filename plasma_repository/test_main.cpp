#include<string>
#include<iostream>

int main()
{
	std::string str("123456");

	auto a = str.begin();
	auto b = str.end();
	auto c = str.rbegin();
	auto d = str.rend();
	std::cout << reinterpret_cast<void const*>(&(*a)) << std::endl;
	std::cout << reinterpret_cast<void const*>(&(*b)) << std::endl;
	std::cout << reinterpret_cast<void const*>(&(*c)) << std::endl;
	std::cout << reinterpret_cast<void const*>(&(*d)) << std::endl;
}