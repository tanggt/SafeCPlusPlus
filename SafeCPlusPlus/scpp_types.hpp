#ifndef _SCPP_TYPES_HPP_INCLUDED_
#define _SCPP_TYPES_HPP_INCLUDED_

#include <ostream>
#include "scpp_assert.hpp"

template <typename T>
class TNumber
{
public:
	TNumber(const T& x = 0):data_(x){}

	operator T() const{ return data_; }

	TNumber& operator = (const T& x)
	{
		data_ = x;
		return *this;
	}
	// x++
	TNumber operator ++ (int)
	{
		TNumber<T> temp(*this);
		++data_;
		return temp;
	}

	// ++x
	TNumber& operator ++ ()
	{
		++data_;
		return *this;
	}
	// +=x
	TNumber& operator += (T x)
	{
		data_ += x;
		return *this;
	}

	// -=x
	TNumber& operator -= (T x)
	{
		data_ -= x;
		return *this;
	}

	// *=x
	TNumber& operator *= (T x)
	{
		data_ *= x;
		return *this;
	}

	// /=x
	TNumber& operator /= (T x)
	{
		SCPP_TEST_ASSERT(x != 0, "Attempt to divide by 0")
			data_ /= x;
		return *this;
	}

	T operator / (T x)
	{
		SCPP_TEST_ASSERT(x != 0, "Attempt to divide by 0")
			return data_ / x;
	}
private:
	T data_;
};

typedef long long int64;
typedef unsigned long long unsigned64;

typedef TNumber<int> Int;
typedef TNumber<unsigned> Unsigned;
typedef TNumber<int64> Int64;
typedef TNumber<unsigned64> Unsigned64;
typedef TNumber<float> Float;
typedef TNumber<double> Double;
typedef TNumber<char> Char;

class Bool
{
public:
	Bool(bool x = false) :data_(x){}

	operator bool() const { return data_; }
	Bool& operator = (bool x)
	{
		data_ = x;
		return *this;
	}
	Bool& operator &= (bool x)
	{
		data_ &= x;
		return *this;
	}
	Bool& operator |= (bool x)
	{
		data_ |= x;
		return *this;
	}
private:
	bool data_;
};
#endif  //_SCPP_TYPES_HPP_INCLUDED_