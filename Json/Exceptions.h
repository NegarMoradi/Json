#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H "EXCEPTIONS_H"

#include<exception>

class Invalid_id :public std::exception
{
public:
	  const char* what() const throw(){ return "Invalid id.\n"; }
};

class Duplicate_key :public std::exception
{
public:
	  const char* what() const throw(){ return "Duplicate key.\n"; }
};

class Undefinded_type :public std::exception
{
public:
	  const char* what() const throw(){ return "Undefinded type.\n"; }
};


#endif
