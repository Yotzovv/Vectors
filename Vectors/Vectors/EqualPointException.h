#ifndef EQUALPOINTEXCEPTION_H
#define EQUALPOINTEXCEPTION_H
#pragma once
#include <exception>
#include <string>


class EqualPointException : public std::exception {
private:
	std::string message_;
public:
	EqualPointException(const std::string& message);
	const char* what() const noexcept override;

};


#endif
