//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>

#include<type_traits>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace concept
	{
		PLASMA_PP_BEGIN_DETAIL_NAMESPACE(has_increment)
		{
			template<class T>auto has_intro_increment_i(T v)->typename sfinae_helper<decltype(++v), std::true_type>::type;
			std::false_type has_intro_increment_i(...);
		}
		struct has_intro_increment
		{
			template<class Target>using type = decltype(detail_has_increment::has_intro_increment_i(Target()));
		};
	}
}