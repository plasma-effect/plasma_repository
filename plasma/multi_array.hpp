//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>
#include<array>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	template<class T, index_t D,index_t I, index_t... Is>struct multi_array
	{
		typedef multi_array<T, D - 1, Is...> value_type;
		std::array<value_type, I> elem_;
		value_type& operator[](index_t i)
		{
			return elem_[i];
		}
		value_type const& operator[](index_t i)const
		{
			return elem_[i];
		}
	};

	template<class T, index_t I>struct multi_array<T, 1, I>
	{
		std::array<T, I> elem_;
		typedef T value_type;
		value_type& operator[](index_t i)
		{
			return elem_[i];
		}
		value_type const& operator[](index_t i)const
		{
			return elem_[i];
		}
	};
}