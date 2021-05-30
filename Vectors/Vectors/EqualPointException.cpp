#include "EqualPointException.h"
#include <string>

EqualPointException:: EqualPointException(const std::string& message) : message_(message)
{
	message_ = message;
}
const char* EqualPointException::what() const noexcept  
{
	return message_.c_str();
}

 const char* what() throw() {
	return "Vector length exception thrown";
}
