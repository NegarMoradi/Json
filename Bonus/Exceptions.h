#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H "EXCEPTIONS_H"

#include<exception>

class Channel_exists :public std::exception
{
public:
	const char* what() const throw();
};

class Channel_does_not_exists :public std::exception
{
public:
	const char* what() const throw();
};

class Same_channel :public std::exception
{
public:
	const char* what() const throw();
};


#endif