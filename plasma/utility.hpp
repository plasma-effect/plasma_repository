//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#define PLASMA_PP_BEGIN_MAIN_NAMESPACE namespace plasma
#define PLASMA_PP_BEGIN_DETAIL_NAMESPACE(name) namespace detail_ ## name

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	typedef unsigned int index_t;

	template<class,class T=void>struct sfinae_helper
	{
		typedef T type;
	};
}