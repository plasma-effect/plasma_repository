//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>
#include<type_traits>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace string
	{
		PLASMA_PP_BEGIN_DETAIL_NAMESPACE(utility)
		{
			template<class Type>struct string_traits
			{
				typedef typename Type::value_type value_type;
				typedef typename Type::basic_string_tag basic_string_tag;
				typedef typename Type::iterator iterator;
			};
			template<class T,size_t N>struct string_traits<T[N]>
			{
				typedef T value_type;
				typedef T basic_string_tag;
				typedef T* iterator;
			};

			template<class T>size_t size(T const& obj)
			{
				return obj.size();
			}
			template<class T, size_t S>size_t size(T const(&ar)[S])
			{
				return S;
			}

			template<class T>void copy(T const& from, typename string_traits<T>::value_type* p)
			{
				from.copy(p);
			}
			template<class T, size_t S>void copy(T const(&from)[S],T* p)
			{
				std::copy(from, from + S, p);
			}
		}
	}
}