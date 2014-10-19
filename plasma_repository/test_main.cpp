#include<plasma/concept/concept_check.hpp>
#include<plasma/concept/concept_or.hpp>
#include<plasma/concept/operator/has_operator_intro_increment.hpp>
#include<plasma/concept/operator/has_operator_post_increment.hpp>
#include<iostream>

struct test{};
typedef plasma::concept::concept_or<plasma::concept::has_intro_increment, plasma::concept::has_post_increment> increment;
template<class T>using type = plasma::type_traits::integral_constant_or_t<increment::type_a<T>, increment::type_b<T>>;

int main()
{
	std::cout << typeid(increment::type_a<int>).name() << std::endl;
	std::cout << typeid(increment::type_b<int>).name() << std::endl;
	std::cout << typeid(plasma::type_traits::integral_constant_or_t<increment::type_a<int>, increment::type_b<int>>).name() << std::endl;
	std::cout << typeid(type<int>).name() << std::endl;
	std::cout << typeid(increment::type<int>).name() << std::endl;
}
#ifndef _MSC_VER
static_assert(false, "");
#endif