#include <iostream>

#include "scpp_refcountptr.hpp"

using std::cout;
using std::endl;
using std::exception;
using std::cerr;

int main(int agrc, char* argv[])
{
	scpp::RefCountPtr<int> p(new int(10));
	cout << *p << endl;
	return 0;
}