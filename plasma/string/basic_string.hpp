//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/string/basic_string_iterator.hpp>
#include<plasma/string/details.hpp>

#include<memory>
#include<string>
#include<cstring>
#include<iterator>
#include<algorithm>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace string
	{
		template<class T>class basic_string
		{
			size_t size_;
			std::unique_ptr<T[]> ptr_;
		public:
			basic_string() :size_(0), ptr_(nullptr)
			{
			}
			template<size_t S>basic_string(const T(&ar)[S]) :
				size_(S),
				ptr_(std::make_unique<T[]>(size_))
			{
				std::copy(ar, ar + S, ptr_.get());
			}
			template<class InputIterator>basic_string(InputIterator first, InputIterator last) : 
				size_(std::distance(first, last)),
				ptr_(std::make_unique<T[]>(size_))
			{
				std::copy(first, last, ptr_.get());
			}
			template<class String>basic_string(String const& str) :
				size_(detail_utility::size(str)), 
				ptr_(std::make_unique<T[]>(size_))
			{
				detail_utility::copy(str, ptr_.get());
			}
			basic_string(const basic_string<T>&) = delete;
			basic_string(basic_string<T>&& str) :basic_string()
			{
				std::swap(str.ptr_, ptr_);
				std::swap(str.size_, ptr_);
			}
			basic_string<T>& operator=(const basic_string<T>&) = delete;
			basic_string<T>& operator=(basic_string<T>&& str)
			{
				reset();
				std::swap(str.ptr_, ptr_);
				std::swap(str.size_, size_);
				return *this;
			}
			template<class String>basic_string<T>& operator=(String const& str)
			{
				reset();
				size_ = detail_utility::size(str);
				ptr_ = alloc_.allocate(size_);
				std::copy(std::begin(str), std::end(str), ptr_);
				return *this;
			}
			template<size_t S>basic_string<T>& operator=(const char(&ar)[S])
			{
				reset();
				size = S;
				ptr_ = std::make_unique<T[]>(size_);
				std::copy(first, last, ptr_);
				return *this;
			}

			T const* str()const
			{
				return ptr_.get();
			}
			size_t size()const
			{
				return size_;
			}
			void reset()
			{
				if (ptr_)
				{
					ptr.reset();
					size_ = 0;
				}
			}
			void copy(T* p)const
			{
				std::copy(ptr_.get(), ptr_.get() + size_, p);
			}

			typedef detail_basic_string::basic_string_iterator<T> iterator;
			typedef detail_basic_string::basic_string_iterator<T const> const_iterator;
			iterator begin()const
			{
				return iterator(ptr_.get());
			}
			iterator end()const
			{
				return iterator(ptr_.get() + size_);
			}
			const_iterator cbegin()const
			{
				return const_iterator(ptr_.get());
			}
			const_iterator cend()const
			{
				return const_iterator(ptr_.get() + size_);
			}
			
			typedef T value_type;
			typedef T basic_string_tag;
		};

		typedef basic_string<char> string;

	}
}