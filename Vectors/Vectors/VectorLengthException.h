#ifndef VECTORLENGTHEXCEPTION_H
#define VECTORLENGTHEXCEPTION_H
#pragma once
#include <exception>
#include <string>


class VectorLengthException : public std::exception {
private:
	std::string message_;
public:
	VectorLengthException();
	const char* what() const noexcept override;

};


#endif
