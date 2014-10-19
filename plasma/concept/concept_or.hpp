//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>
#include<plasma/type_traits/integral_constant_or.hpp>
#include<plasma/concept/concept_check.hpp>
#include<type_traits>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace concept
	{
		template<class ConceptA, class ConceptB>struct concept_or
		{
			template<class Target>using type_a = plasma::concept::concept_check<ConceptA, Target>;
			template<class Target>using type_b = plasma::concept::concept_check<ConceptB, Target>;
			template<class Target>using type = plasma::type_traits::integral_constant_or_t<type_a<Target>,type_b<Target>>;
			//template<class Target>using type=std::integral_constant<bool,(type_a<int>::value || type_b<int>::value)>;
		};
	}
}