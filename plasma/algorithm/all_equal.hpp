//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>
#include<iterator>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace algorithm
	{
		template<class InputIterator>bool all_equal(InputIterator first, InputIterator last)
		{
			if (first==last)
				return true;
			for (InputIterator next = std::next(first);
				next != last;
				[&](){++next; ++first; }())
			{
				if (*first != *next)
					return false;
			}
			return true;
		}
	}
}