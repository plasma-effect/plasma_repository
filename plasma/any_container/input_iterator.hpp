//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<plasma/utility.hpp>
#include<plasma/exception.hpp>

#include<iterator>
#include<memory>
#include<typeinfo>

PLASMA_PP_BEGIN_MAIN_NAMESPACE
{
	namespace any_container
	{
#		define THIS_TYPE input_iterator
		template<class ValueType>struct input_iterator :std::iterator<std::input_iterator_tag, ValueType>
		{
			struct place_holder_t
			{
				virtual value_type const& get_value() const = 0;//operator*()
				virtual void succ() = 0;//operator++()
				virtual std::type_info const& get_type_info()const = 0;//return hold type
				virtual std::unique_ptr<place_holder_t> clone()const = 0;//for copy construct
				virtual bool equal(place_holder_t const*)const PLASMA_PP_NOEXCEPT() = 0;//operator==()
			};

			template<class InputIterator>struct place_holder_type:place_holder_t
			{
				InputIterator ite_;

				place_holder_type(InputIterator ite=InputIterator()) :
					ite_(ite)
				{

				}
				
				value_type const& get_value()const final override
				{
					return *ite_;
				}
				void succ()final override
				{
					++ite_;
				}
				std::type_info const& get_type_info()const final override
				{
					return typeid(InputIterator);
				}
				std::unique_ptr<place_holder_t> clone()const final override
				{
					return std::make_unique<place_holder_type<InputIterator>>(ite_);
				}
				bool equal(place_holder_t const* ptr)const PLASMA_PP_NOEXCEPT() final override
				{
					return ((get_type_info() == ptr->get_type_info()) && (ite_ == reinterpret_cast<place_holder_type<InputIterator> const*>(ptr)->ite_));
				}
			};
			std::unique_ptr<place_holder_t> place_holder_;

			THIS_TYPE() :
				place_holder_(nullptr){}
			template<class InputIterator>THIS_TYPE(InputIterator iterator) :
				place_holder_(std::make_unique<place_holder_type<InputIterator>>(iterator)){}
			THIS_TYPE(THIS_TYPE const& arg):
				place_holder_(arg.place_holder_->clone()){}
			THIS_TYPE(THIS_TYPE&& arg):
				place_holder_(std::move(arg.place_holder_)){}
			THIS_TYPE& operator=(THIS_TYPE const& arg)
			{
				place_holder_ = arg.place_holder_->clone();
				return *this;
			}
			THIS_TYPE operator=(THIS_TYPE&& arg)
			{
				place_holder_ = std::move(arg.place_holder_);
				return *this;
			}
			~THIS_TYPE() = default;

			value_type const& operator*()const
			{
				if (place_holder_)
					return place_holder_->get_value();
				throw exception::null_pointer_access_exception("**plasma::any_container::input_iterator::operator*(): Null pointer exception(not have any [InputIterator])**");
			}
			THIS_TYPE& operator++()
			{
				if (!place_holder_)
					throw exception::null_pointer_access_exception("**plasma::any_container::input_iterator::operator++(): Null pointer exception(not have any [InputIterator])**");
				place_holder_->succ();
				return *this;
			}
			THIS_TYPE operator++(int)
			{
				auto ret = *this; 
				if (!place_holder_)
					throw exception::null_pointer_access_exception("**plasma::any_container::input_iterator::operator++(int): Null pointer exception(not have any [InputIterator])**");
				place_holder_->succ();
				return ret;
			}
			bool operator==(THIS_TYPE const& rhs)const PLASMA_PP_NOEXCEPT()
			{
				if (place_holder_)
				{
					if (rhs.place_holder_)
						return place_holder_->equal(rhs.place_holder_.get());
					return false;
				}
				return !rhs.place_holder_;
			}
			bool operator!=(THIS_TYPE const& rhs)const PLASMA_PP_NOEXCEPT()
			{
				return !operator==(rhs);
			}
		};
#		undef THIS_TYPE
	}
}