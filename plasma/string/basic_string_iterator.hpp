//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>

#include<boost/operators.hpp>

#include<iterator>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace string
	{
		PLASMA_PP_BEGIN_DETAIL_NAMESPACE(basic_string)
		{
			template<class T>struct basic_string_iterator :
				std::iterator<std::random_access_iterator_tag, T>,
				boost::addable<basic_string_iterator<T>>,
				boost::subtractable<basic_string_iterator<T>>
			{
				T* ptr_;

				explicit basic_string_iterator(T* ptr = nullptr) :ptr_(ptr)
				{
				}
				basic_string_iterator(basic_string_iterator<T> const& arg) :ptr_(arg.ptr_)
				{
				}
				basic_string_iterator(basic_string_iterator<T>&& arg) :ptr_(arg.ptr_)
				{
					arg.ptr_ = nullptr;
				}
				basic_string_iterator<T>& operator=(basic_string_iterator<T>const& arg)
				{
					ptr_ = arg.ptr_;
					return *this;
				}
				basic_string_iterator<T>& operator=(basic_string_iterator<T>&& arg)
				{
					ptr_ = arg.ptr_;
					arg.ptr_ = nullptr;
					return *this;
				}

				basic_string_iterator<T>& operator+=(int n)
				{
					ptr_ += n;
					return *this;
				}
				basic_string_iterator<T>& operator-=(int n)
				{
					ptr_ -= n;
					return *this;
				}
				bool operator==(basic_string_iterator<T> const& rhs)const
				{
					return ptr_ == rhs.ptr_;
				}
				bool operator!=(basic_string_iterator<T> const& rhs)const
				{
					return ptr_ != rhs.ptr_;
				}

				T& operator*()
				{
					return *ptr_;
				}
				T const& operator*()const
				{
					return *ptr_;
				}
				T& operator[](index_t i)
				{
					return ptr_[i];
				}
				T const& operator[](index_t i)const
				{
					return ptr_[i];
				}

				basic_string_iterator<T>& operator++()
				{
					++ptr_;
					return *this;
				}
				basic_string_iterator<T> operator++(int)
				{
					auto ret = *this;
					++ptr_;
					return ret;
				}
				basic_string_iterator<T>& operator--()
				{
					--ptr_;
					return *this;
				}
				basic_string_iterator<T> operator--(int)
				{
					auto ret=*this
					--ptr_;
					return ret;
				}


			};
		}
	}
}