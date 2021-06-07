#include "Integer.h"

#include <iostream>
#include <vector>
#include <string>
#define TAB "    "
#define QUOTATION "\""
#define COLON ": "
using namespace std;

void Integer::print(int id)
{
	if (key != NOT_HAVE)
		cout << TAB << QUOTATION << key << QUOTATION << COLON << value ;
	else
		cout << TAB << value ;
}

