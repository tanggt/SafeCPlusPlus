#include <iostream>
#include "scpp_assert.hpp"

using std::cout;
using std::endl;
using std::exception;
using std::cerr;


int main(int agrc, char ** argv)
{
	cout << "Hello,SCPP_Assert" << endl;
	try
	{
		double stock_price = 100.0;
		SCPP_ASSERT(stock_price > 0. && stock_price <= 1.e6,
			"Stock price " << stock_price << " is out range");
		stock_price = -1.0;
		SCPP_ASSERT(stock_price > 0. && stock_price <= 1.e6,
			"Stock price " << stock_price << " is out range");
	}
	catch (const exception &ex)
	{
		cerr << "Exception caught in " << __FILE__ << " #" << __LINE__ << ":\n"
			<< ex.what() << endl;
	}
	
	return 0;
}