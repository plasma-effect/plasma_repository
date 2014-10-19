//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>

#include<type_traits>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace type_traits
	{
		template<class T, class U>struct integral_constant_or;
		template<bool F0, bool F1>struct integral_constant_or<std::integral_constant<bool, F0>, std::integral_constant<bool, F1>>
		{
			typedef std::integral_constant<bool, (F0 || F1)> type;
		};
		template<class T, class U>using integral_constant_or_t = typename integral_constant_or<T, U>::type;
	}
}