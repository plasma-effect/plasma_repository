//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#define PLASMA_PP_BEGIN_MAIN_NAMESPACE namespace plasma
#define PLASMA_PP_BEGIN_DETAIL_NAMESPACE(name) namespace detail_ ## name


#if defined(_MSC_VER) && (_MSC_VER <= 1800)
#define PLASMA_PP_NOEXCEPT() throw()
#define PLASMA_CONSTEXPR_OR_NULL
#define PLASMA_CONSTEXPR_OR_CONST const
#else
#define PLASNA_PP_NOEXCEPT() noexcept
#define PLASMA_CONSTEXPR_OR_NULL constexpr
#define PLASMA_CONSTEXPR_OR_CONST constexpr
#endif

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	typedef unsigned int index_t;
	typedef unsigned int size_t;

	template<class,class T=void>struct sfinae_helper
	{
		typedef T type;
	};
}