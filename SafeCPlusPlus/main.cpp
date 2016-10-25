#include <iostream>
#include <algorithm>

#include "scpp_matrix.hpp"

using std::cout;
using std::endl;
using std::exception;
using std::cerr;


int main(int agrc, char ** argv)
{
	scpp::matrix<int> m(2, 3, 99);
	for (unsigned i = 0; i < m.row(); ++i)
	{
		for (unsigned j = 0; j < m.column(); ++j)
		{
			cout << m(1, 1);
			if (m.column() > i + 1)
				cout << " ";
		}
		cout << endl;
	}
			
	return 0;
}