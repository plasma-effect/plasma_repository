//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/string/details.hpp>
#include<iterator>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace string
	{
		PLASMA_PP_BEGIN_DETAIL_NAMESPACE(string_add)
		{
			template<class Lhs, class Rhs,class Lhs_I,class Rhs_I,class T>struct string_add
			{
				Lhs lhs_;
				Rhs rhs_;
				size_t lhs_size_;
				size_t rhs_size_;
				string_add(Lhs lhs, Rhs rhs) :
					lhs_(lhs), 
					rhs_(rhs),
					lhs_size_(detail_utility::size(lhs)),
					rhs_size_(detail_utility::size(rhs)){}
				

				size_t size()const
				{
					return lhs_size_ + rhs_size_ - 1;
				}
				void copy(T* p)const
				{
					detail_utility::copy(lhs_, p);
					detail_utility::copy(rhs_, p + lhs_size_ - 1);
				}

				typedef T value_type;
				typedef string_add<Lhs, Rhs,Lhs_I,Rhs_I, T> type;
				typedef T basic_string_tag;
				
				using l_iterator = Lhs_I;
				using r_iterator = Rhs_I;


				struct iterator :std::iterator<std::bidirectional_iterator_tag, T>
				{
					l_iterator lhs_ite_;
					r_iterator rhs_ite_;
					l_iterator lhs_end_;
					r_iterator rhs_beg_;
					bool flag_;

					iterator& operator++()
					{
						if (flag_)
						{
							++rhs_ite_;
						}
						else
						{
							++lhs_ite_;
							flag_ = (lhs_ite_ == lhs_end_);
						}
						return *this;
					}
					iterator operator++(int)
					{
						auto ret = *this;
						if (flag_)
						{
							++rhs_ite_;
						}
						else
						{
							++lhs_ite_;
							flag_ = (lhs_ite_ == lhs_end_);
						}
						return ret;
					}
					iterator& operator--()
					{
						if (flag_)
						{
							if (rhs_ite_ == rhs_beg_)
							{
								flag_ = false;
								--lhs_ite_;
							}
							else
							{
								--rhs_ite_;
							}
						}
						else
						{
							--lhs_ite_;
						}
						return *this;
					}
					iterator operator--(int)
					{
						auto ret = 0;
						if (flag_)
						{
							if (rhs_ite_ == rhs_beg_)
							{
								flag_ = false;
								--lhs_ite_;
							}
							else
							{
								--rhs_ite_;
							}
						}
						else
						{
							--lhs_ite_;
						}
						return *this;
					}
					value_type operator*()const
					{
						return (flag_ ? *rhs_ite_ : *lhs_ite_);
					}
					bool operator==(iterator const& ite)const
					{
						return (flag_ ? 
							(ite.flag_ && (rhs_ite_ == ite.rhs_ite_)) :
							(!ite.flag_ &&(lhs_ite_ == ite.lhs_ite_)));
					}
					bool operator!=(iterator const& ite)const
					{
						return !operator==(ite);
					}
					iterator(l_iterator l, r_iterator r, l_iterator e,r_iterator b, bool f) :
						lhs_ite_(l),
						rhs_ite_(r), 
						lhs_end_(e),
						rhs_beg_(b),
						flag_(f){}
				};
				iterator begin()const
				{
					return iterator(std::begin(lhs_), std::begin(rhs_), std::prev(std::end(lhs_)), std::end(rhs_), false);
				}
				iterator end()const
				{
					auto r = std::prev(std::end(lhs_));
					return iterator(r, std::end(rhs_), r, std::begin(rhs_), true);
				}
			};
		}
		template<class Lhs, class Rhs>auto
			operator+(Lhs const& lhs, Rhs const& rhs)
			->detail_string_add::string_add <
				Lhs const&,
				Rhs const&,
				typename detail_utility::string_traits<Lhs>::iterator,
				typename detail_utility::string_traits<Rhs>::iterator,
				std::remove_const_t<typename detail_utility::string_traits<Lhs>::basic_string_tag>>
		{
			return detail_string_add::string_add<
				Lhs const&,
				Rhs const&,
				typename detail_utility::string_traits<Lhs>::iterator,
				typename detail_utility::string_traits<Rhs>::iterator,
				std::remove_const_t<typename detail_utility::string_traits<Lhs>::basic_string_tag>>(lhs, rhs);
		}

			
	}
}