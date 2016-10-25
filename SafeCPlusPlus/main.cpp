#include <iostream>
#include "scpp_vector.hpp"

using std::cout;
using std::endl;
using std::exception;
using std::cerr;


int main(int agrc, char ** argv)
{
	scpp::vector<int> vect;
	for (int i = 0; i < 3; i++)
	{
		vect.push_back(i);
	}
	
	cout << "My vector = " << vect << endl;
	for (unsigned int i = 0; i < vect.size(); ++i)
	{
		cout << "Value of vector at " << i << " is " << vect[i] << endl;
	}
	return 0;
}