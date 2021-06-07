#include "String.h"

#include <iostream>
#include <vector>
#include <string>

#define TAB "    "
#define QUOTATION "\""
#define COLON ": "
#define NOT_HAVE "not_have"
using namespace std;


void String::print(int id)
{
	if (key != NOT_HAVE)
		cout << TAB << QUOTATION << key << QUOTATION << COLON << QUOTATION << value << QUOTATION ;
	else
		cout << TAB << QUOTATION << value << QUOTATION ;
}
