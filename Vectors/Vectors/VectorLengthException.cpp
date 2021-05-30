#include "VectorLengthException.h"
#include <string>

VectorLengthException::VectorLengthException()
{
}

const char* VectorLengthException::what() const throw() {
	return "Vector length exception thrown";
}
