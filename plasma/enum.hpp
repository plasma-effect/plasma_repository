//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#ifndef BOOST_PP_VARIADICS
#define BOOST_PP_VARIADICS
#endif
#include<boost/preprocessor.hpp>
#include<plasma/utility.hpp>

#define PLASMA_ENUM(name,...) PLASMA_ENUM_I_MAKE_ENUM_CLASS(name,__VA_ARGS__) PLASMA_ENUM_I_MAKE_OPERATORS(name,__VA_ARGS__)

#define PLASMA_ENUM_I_MAKE_ENUM_CLASS(name,...) enum class name{__VA_ARGS__};

#define PLASMA_ENUM_I_MAKE_OPERATORS(name,...)\
	PLASMA_ENUM_I_MAKE_INCREMENT(name,__VA_ARGS__)\
	PLASMA_ENUM_I_MAKE_DECREMENT(name, __VA_ARGS__)
#define PLASMA_ENUM_I_MAKE_INCREMENT(name,...)\
	name& operator++(name& t)\
	{\
		if(t != name:: BOOST_PP_TUPLE_ELEM(BOOST_PP_SUB(BOOST_PP_TUPLE_SIZE((__VA_ARGS__)),1),(__VA_ARGS__)))\
			t = static_cast<name>(static_cast<int>(t)+1);\
		else\
			t = name:: BOOST_PP_TUPLE_ELEM(0,(__VA_ARGS__));\
		return t;\
	}\
	name operator++(name& t,int)\
	{\
		auto ret = t;\
		++t;\
		return ret;\
	}
#define PLASMA_ENUM_I_MAKE_DECREMENT(name,...)\
	name& operator--(name& t)\
	{\
		if (t != name:: BOOST_PP_TUPLE_ELEM(0, (__VA_ARGS__)))\
			t = static_cast<name>(static_cast<int>(t)-1); \
		else\
			t = name:: BOOST_PP_TUPLE_ELEM(BOOST_PP_SUB(BOOST_PP_TUPLE_SIZE((__VA_ARGS__)), 1), (__VA_ARGS__)); \
		return t; \
	}\
	name operator--(name& t, int)\
	{\
		auto ret = t; \
		--t; \
		return ret; \
	}