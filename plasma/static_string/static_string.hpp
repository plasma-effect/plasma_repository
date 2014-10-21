//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>

#include<iterator>
#include<array>
#include<algorithm>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace static_string
	{
		template<class CharType,size_t Size>class static_string
		{
		public:
			static const size_t max_size = Size;
			typedef CharType value_type;
			typedef static_string<CharType, Size> this_type;
		
			struct const_iterator :std::iterator<std::random_access_iterator_tag, value_type>
			{
				typedef const_iterator this_type;
				value_type* ptr;
				const_iterator(value_type* p = nullptr) :ptr(p){}
				const_iterator(this_type& const) = default;
				const_iterator(this_type&& arg) :iterator()
				{
					std::swap(arg.ptr, ptr);
				}
				this_type& operator=(this_type const& arg)
				{
					ptr = arg.ptr;
					return *this;
				}
				this_type& operator=(this_type&& arg)
				{
					ptr = arg.ptr;
					arg.ptr = nullptr;
					return *this;
				}

				this_type& operator++()
				{
					++ptr;
					return *this;
				}
				this_type operator++(int)
				{
					auto ret = *this;
					++ptr;
					return ret;
				}
				this_type& operator--()
				{
					--ptr;
					return *this;
				}
				this_type operator--(int)
				{
					auto ret = *this;
					--ptr;
					return ret;
				}
				this_type operator+(int n)const
				{
					return this_type(ptr + n);
				}
				this_type operator-(int n)const
				{
					return this_type(ptr - n);
				}
				auto operator-(this_type const& ite)const->decltype(ptr - ite.ptr)
				{
					return ptr - ite.ptr;
				}

				value_type const& operator*()const
				{
					return *ptr;
				}
				value_type const& operator[](index_t i)const
				{
					return ptr[i];
				}
			};
			struct iterator :std::iterator<std::random_access_iterator_tag, value_type>
			{
				typedef iterator this_type;
				value_type* ptr;
				iterator(value_type* p = nullptr) :ptr(p){}
				iterator(this_type& const) = default;
				iterator(this_type&& arg) :iterator()
				{
					std::swap(arg.ptr, ptr);
				}
				this_type& operator=(this_type const& arg)
				{
					ptr = arg.ptr;
					return *this;
				}
				this_type& operator=(this_type&& arg)
				{
					ptr = arg.ptr;
					arg.ptr = nullptr;
					return *this;
				}

				this_type& operator++()
				{
					++ptr;
					return *this;
				}
				this_type operator++(int)
				{
					auto ret = *this;
					++ptr;
					return ret;
				}
				this_type& operator--()
				{
					--ptr;
					return *this;
				}
				this_type operator--(int)
				{
					auto ret = *this;
					--ptr;
					return ret;
				}
				this_type operator+(int n)const
				{
					return this_type(ptr + n);
				}
				this_type operator-(int n)const
				{
					return this_type(ptr - n);
				}
				auto operator-(this_type const& ite)const->decltype(ptr - ite.ptr)
				{
					return ptr - ite.ptr;
				}

				value_type& operator*()const
				{
					return *ptr;
				}
				value_type& operator[](index_t i)const
				{
					return ptr[i];
				}

				operator const_iterator()
				{
					return const_iterator(ptr);
				}
			};
			typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef std::reverse_iterator<iterator> reverse_iterator;

		private:
			typedef std::array<CharType, Size + 1> array_type;
			
			array_type elem_;
			size_t size_;
			
		public:
			static_string() :elem_{}, size_(0){}
			static_string(const static_string& str) :elem_(str.elem_), size_(str.size_){}
			static_string(static_string&& str) :static_string()
			{
				std::swap(elem_, str.elem_);
				std::swap(size_, str.size_);
			}
			this_type operator=(this_type const& str)
			{
				elem_ = str.elem_;
				size_ = str.size_;
			}
			this_type operator=(this_type&& str)
			{
				std::swap(elem_, str.elem_);
				std::swap(size_, str.size_);
				str.elem_ = array_type{};
				str.size_ = 0;
			}
			template<size_t N>
			static_string(value_type const(&ar)[N]) :elem_{}, size_(N-1)
			{
				static_assert(N <= (max_size + 1), "static_string(value_type const(&ar)[N]): N must under than or equal to Size+1");
				std::copy(std::begin(ar), std::end(ar), std::begin(elem_));
				
			}

			const value_type* c_str()const
			{
				return &(elem_[0]);
			}
			
			iterator begin()const
			{
				return iterator(c_str());
			}
			iterator end()const
			{
				return iterator(c_str() + max_size + 1);
			}
			const_iterator cbegin()const
			{
				return const_iterator(c_str());
			}
			const_iterator cend()const
			{
				return const_iterator(c_str() + max_size + 1);
			}
			reverse_iterator rbegin()const
			{
				return reverse_iterator(c_str() + max_size);
			}
			reverse_iterator rend()const
			{
				return reverse_iterator(c_str() - 1);
			}
			const_reverse_iterator rbegin()const
			{
				return const_reverse_iterator(c_str() + max_size);
			}
			const_reverse_iterator rend()const
			{
				return const_reverse_iterator(c_str() - 1);
			}

			size_t size()const
			{
				return size_;
			}
		};
	}
}