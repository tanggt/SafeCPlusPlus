#include "scpp_assert.hpp"

#include <iostream>
#include <stdlib.h>

using std::cerr;
using std::endl;
using std::ostringstream;

#ifdef _SCPP_THROW_EXCEPTION_ON_BUG
namespace scpp
{
	ScppAssertFailedException::ScppAssertFailedException(const char *file_name,
		unsigned line_number,
		const char *message)
	{
		ostringstream s;
		s << "SCPP assertion failed with message '" << message
			<< "' in file " << file_name << " #" << line_number;

		what_ = s.str();
	}
}
#endif
     
void SCPP_AssertErrorHandler(const char *file_name,
	unsigned line_number,
	const char *message)
{
#ifdef _SCPP_THROW_EXCEPTION_ON_BUG
	throw scpp::ScppAssertFailedException(file_name, line_number, message);
#else
	cerr << message << " in file " << file_name << " #" << line_number << endl;
	// Terminate application
	exit(1);
#endif

}
