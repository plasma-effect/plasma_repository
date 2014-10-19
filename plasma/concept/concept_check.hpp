//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace concept
	{
		template<class Concept, class Target>using concept_check = typename Concept::template type<Target>;
	}
}