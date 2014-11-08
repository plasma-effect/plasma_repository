//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace algorithm
	{
		PLASMA_PP_BEGIN_DETAIL_NAMESPACE(rotate)
		{
			template<class V,class T, class T2, class... Ts>void rotate_i(V const& v, T& arg, T2& arg2, Ts&... args)
			{
				arg = arg2;
				rotate_i(v, arg2, args...);
			}
			template<class V, class T>void rotate_i(V const& v, T& arg)
			{
				arg = v;
			}
		}
		template<class T, class... Ts>void rotate(T& arg, Ts&... args)//args rotate to left
		{
			T v = arg;
			detail_rotate::rotate_i(v, arg, args...);
		}
	}
}