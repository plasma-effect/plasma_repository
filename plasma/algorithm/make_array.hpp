//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>
#include<plasma/type_traits/index_tuple.hpp>

#include<array>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace algorithm
	{
		PLASMA_PP_BEGIN_DETAIL_NAMESPACE(make_array)
		{
			template<class T, index_t Size, class F, class IndexTuple>struct make_array_i;
			template<class T, index_t Size, class F, index_t... Is>struct make_array_i<T, Size, F, index_tuple::index_tuple<Is...>>
			{
				static std::array<T, Size> run(F func)
				{
					return std::array< T, Size >{{func(Is)...}};
				}
			};
			template<class T>struct echo
			{
				T operator()(index_t N)
				{
					return static_cast<T>(N);
				}
			};
		}

		template<class T, index_t Begin, index_t End, class F>std::array<T, End - Begin> make_array(F func)
		{
			return detail_make_array::make_array_i<T, End - Begin, F, index_tuple::index_range_t<Begin,End>>::run(func);
		}
		template<class T, index_t Begin, index_t End>std::array<T, End - Begin> make_array()
		{
			return make_array<T, Begin, End>(detail_make_array::echo<T>());
		}
	}
}