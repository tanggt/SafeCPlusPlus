#ifndef __SCPP_ASSERT_HPP_INCLUDEED__
#define __SCPP_ASSERT_HPP_INCLUDEED__

#include <sstream>

#ifdef _SCPP_THROW_EXCEPTION_ON_BUG
#include <exception>

namespace scpp
{
	class ScppAssertFailedException : public std::exception
	{
	public:
		ScppAssertFailedException(const char *file_name,
			unsigned line_number,
			const char *message);
		virtual const char* what() const throw()
		{
			return what_.c_str();
		}
		virtual ~ScppAssertFailedException() throw (){}
	private:
		std::string what_;
	};
}
#endif

void SCPP_AssertErrorHandler(const char *file_name,
	unsigned line_number,
	const char *message);

#define SCPP_ASSERT(condition,msg)        \
	   if(!(condition))                   \
	   {						          \
		   std::ostringstream s;          \
		   s << msg;                      \
		   SCPP_AssertErrorHandler(       \
		   __FILE__,__LINE__,s.str().c_str()); \
	   }

#ifdef _DEBUG
#define _SCPP_TEST_ASSERT_ON
#endif

#ifdef _SCPP_TEST_ASSERT_ON
#define SCPP_TEST_ASSERT(condition, msg) SCPP_ASSERT(condition,msg)
#else
#define SCPP_TEST_ASSERT(condition, msg)
#endif

#endif  //__SCPP_ASSERT_HPP_INCLUDEED__