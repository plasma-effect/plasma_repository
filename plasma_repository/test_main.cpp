#include<plasma/string/basic_string.hpp>
#include<plasma/string/operator_add.hpp>
#include<iostream>
//#include<plasma/string/details.hpp>

int main()
{
	plasma::string::string str ="456";
	plasma::string::string str2 = str + "123";
	plasma::string::string str3 = "123" + str2;
	std::cout << str2.str() << std::endl;
}