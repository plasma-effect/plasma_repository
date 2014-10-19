//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace index_tuple
	{
		template<index_t...>struct index_tuple;
		PLASMA_PP_BEGIN_DETAIL_NAMESPACE(index_count)
		{
			template<index_t N, class IndexTuple, bool IsEven>struct index_count_i;
			template<index_t N, index_t... Is>struct index_count_i<N, index_tuple<Is...>, true>
			{
				typedef index_tuple<Is..., (Is + N)..., 2 * N> type;
			};
			template<index_t N, index_t... Is>struct index_count_i<N, index_tuple<Is...>, false>
			{
				typedef index_tuple<Is..., (Is + N)...> type;
			};
		}
		template<index_t N>struct index_count
		{
			typedef typename detail_index_count::index_count_i<N / 2, typename index_count<N / 2>::type, N % 2>::type type;
		};
		template<>struct index_count<0>
		{
			typedef index_tuple<> type;
		};
		template<index_t N>using index_count_t = typename index_count<N>::type;

		PLASMA_PP_BEGIN_DETAIL_NAMESPACE(index_range)
		{
			template<index_t N, class IndexTuple>struct index_range_i;
			template<index_t N, index_t... Is>struct index_range_i < N, index_tuple<Is...> >
			{
				typedef index_tuple<(Is + N)...> type;
			};
		}
		template<index_t B, index_t E>struct index_range
		{
			typedef typename detail_index_range::index_range_i<B, index_count_t<E - B>>::type type;
		};
		template<index_t B, index_t E>using index_range_t = typename index_range<B, E>::type;
	}
}