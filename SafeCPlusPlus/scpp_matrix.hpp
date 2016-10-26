#ifndef _SCPP_MATRIX_HPP_INCLUDED_
#define _SCPP_MATRIX_HPP_INCLUDED_

#include <vector>
#include <ostream>

#include "scpp_assert.hpp"

namespace scpp{
	template <typename T>
	class matrix
	{
	public :
		typedef unsigned size_type;
		matrix(size_type num_rows, size_type num_columns)
			:rows_(num_rows), columns_(num_columns)
		{
			SCPP_TEST_ASSERT(num_rows > 0,
				"Numbers of rows in a matrix must be positive");
			SCPP_TEST_ASSERT(num_columns > 0,
				"Numbers of columns in a matrix must be positive");
		}

		matrix(size_type num_rows, size_type num_columns, const T& init_value)
			:rows_(num_rows), columns_(num_columns), data_(num_rows*num_columns,init_value)
		{
			SCPP_TEST_ASSERT(num_rows > 0,
				"Numbers of rows in a matrix must be positive");
			SCPP_TEST_ASSERT(num_columns > 0,
				"Numbers of columns in a matrix must be positive");
		}

		size_type row(){ return rows_; }
		size_type  column(){ return columns_; }

		T& operator ()(size_type row, size_type column)
		{
			return data_[index(row, column)];
		}

		const T& operator ()(size_type row, size_type column) const 
		{
			return data_[index(row, column)];
		}
	private:
		size_type rows_;
		size_type columns_;
		std::vector<T> data_;
		size_type index(size_type row, size_type column) const
		{
			SCPP_TEST_ASSERT(row > 0,
				"Numbers of rows in a matrix must be positive");
			SCPP_TEST_ASSERT(column > 0,
				"Numbers of columns in a matrix must be positive");
			return columns_*row + column;
		}
	};
} // namespace scpp

//template <typename T>
//inline std::ostream& operator << (std::ostream& os, const scpp::matrix<T>& m)
//{
//	for (unsigned i = 0; i < m.row(); ++i)
//	{
//		for (unsigned j = 0; j < m.column(); ++j)
//		{
//			os << m(i, j);
//			if (m.column() > i + 1)
//				os << " ";
//		}
//		os << "\n";
//	}
//	return os;
//}

#endif // _SCPP_MATRIX_HPP_INCLUDED_
