//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/static_string/static_string.hpp>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace static_string
	{
		template<class CharType, size_t SizeA, size_t SizeB>
		static_string<CharType, SizeA + SizeB> 
			operator+(static_string<CharType, SizeA> const& lhs, static_string<CharType, SizeB> const& rhs)
		{
			static_string<CharType, SizeA + SizeB> ret{};
			auto ptr = ret.c_str();
			std::copy(lhs.c_str(), lhs.c_str() + lhs.size() + 1, ptr);
			std::copy(rhs.c_str(), rhs.c_str() + rhs.size() + 1, ptr + lhs.size() + 1);
		}
	}
}