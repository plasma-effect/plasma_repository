//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>

#include<stdexcept>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace exception
	{
		class null_pointer_access_exception:public std::runtime_error
		{
		public:
			null_pointer_access_exception(char const* message="null pointer exception"):
				runtime_error(message){}
		};
	}
}