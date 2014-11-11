//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#ifndef BOOST_PP_VARIADICS
#define BOOST_PP_VAROADICS
#endif
#include<plasma/utility.hpp>
#include<boost/preprocessor.hpp>

#define PLASMA_PP_EXTEND_SWITCH(switch_on,top,...)\
	([&]()->PLASMA_PP_ENTEND_SWITCH_I3 top{\
		switch(switch_on)\
		{\
		BOOST_PP_SEQ_FOR_EACH(\
			PLASMA_PP_EXTEND_SWITCH_I,,\
			BOOST_PP_TUPLE_TO_SEQ((top,__VA_ARGS__)))}})()
#define PLASMA_PP_EXTEND_SWITCH_I(r,z,arg) PLASMA_PP_EXTEND_SWITCH_I2 arg
#define PLASMA_PP_EXTEND_SWITCH_I2(pattern, func) case pattern: return func;
#define PLASMA_PP_ENTEND_SWITCH_I3(pattern, func) decltype(func)