#ifndef _SCPP_REFCOUNTPTR_HPP_INCLUDED_
#define _SCPP_REFCOUNTPTR_HPP_INCLUDED_

#include "scpp_assert.hpp"

namespace scpp{
	template <typename T>
	class RefCountPtr
	{
	public:
		explicit RefCountPtr(T* p=NULL)
		{
			Create(p);
		}
		RefCountPtr(const RefCountPtr<T>& rhs)
		{
			Copy(rhs);
		}
		RefCountPtr<T>& operator =(const RefCountPtr<T>& rhs)
		{
			if (rhs.ptr_ != ptr_)
			{
				Kill();
				Copy(rhs);
			}
			return *this;
		}

		RefCountPtr<T>& operator =(T* p)
		{
			if (p!= ptr_)
			{
				Kill();
				Create(p);
			}
			return *this;
		}

		T* Get(){ return ptr_; }

		T* operator ->() const
		{
			SCPP_TEST_ASSERT(ptr_ != NULL, "Attempt to use operator -> on NULL pointer.");
			return ptr_;
		}

		T& operator *() const
		{
			SCPP_TEST_ASSERT(ptr_ != NULL, "Attempt to use operator * on NULL pointer.");
			return *ptr_;
		}
		~RefCountPtr()
		{
			Kill();
		}

	private:
		T* ptr_;
		int* count_;
		void Create(T* p)
		{
			ptr_ = p;
			if (ptr_ != NULL)
			{
				count_ = new int;
				*count_ = 1;
			}
			else
			{
				count_ = NULL;
			}
		}
		void Copy(const RefCountPtr<T>& rhs)
		{
			ptr_ = rhs.ptr_;
			count_ = rhs.count_;
			if (count_ != NULL)
				++(count_);
		}
		void Kill()
		{
			if (count_ != NULL)
			{
				if (--(*count_) == 0)
				{
					delete ptr_;
					delete count_;
				}
			}
		}
	};
}
#endif