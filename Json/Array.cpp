#include "Array.h"
#include "Exceptions.h"
#include "Integer.h"
#include "String.h"
#include "Object.h"

#include <iostream>
#include <vector>
#include <string>

#define TAB "    "
#define QUOTATION "\""
#define COLON ": "
#define COMMA ","
#define ONE 1
#define ZERO 0
#define OBJECT "object"
#define ARRAY "array"
#define BRACKET "[]"
#define L_BRACKET "["
#define R_BRACKET "]"

using namespace std;

void Array::check_type(std::string type_)
{
	if (type_ != OBJECT && type_ != ARRAY)
		throw Undefinded_type();
}

void Array::print(int id)
{
	if (key != NOT_HAVE)
	{
		if (datas.size() == ZERO)
			cout << TAB << QUOTATION << key << QUOTATION << COLON << BRACKET;
		else
		{
			cout << TAB << QUOTATION << key << QUOTATION << COLON << L_BRACKET << endl;
			print_for_big_data(id);
		}
	}
	else
	{
		if (datas.size() == ZERO)
			cout << TAB << BRACKET;
		else
		{
			cout << TAB << L_BRACKET << endl;
			print_for_big_data(id);
		}
	}

}
void Array::print_for_big_data(int id)
{
	if (datas.size() > 1)
	{
		cout << TAB;
		datas[0]->print(id);
		cout << COMMA << endl;
		for (int i = 1; i < datas.size() - 1; i++)
		{
			cout << TAB;
			datas[i]->print(id);
			cout << COMMA << endl;
		}
		cout << TAB;
		datas[datas.size() - 1]->print(id);
		cout << endl;
		cout << TAB << R_BRACKET;
	}
	else if (datas.size() == ONE)
		print_for_data_one(id);
}
void Array::print_for_data_one(int id)
{
	cout << TAB ;
	datas[datas.size() - 1]->print(id);
	cout << endl;
	cout << TAB << R_BRACKET;
}

void Array::check_key(string key_)
{
	for (int i = 0; i < datas.size(); i++)
		if (datas[i]->has_same_key(key_))
			throw Duplicate_key();

}
void Array::add_string(std::string key, std::string value)
{
	check_key(key);
	datas.push_back(new String(value));
}
void Array::add_integer(std::string key, int value)
{
	check_key(key);
	datas.push_back(new Integer(value));
}

int Array::add_object(std::string key, std::string type)
{
	check_key(key);
	check_type(type);
	datas.push_back(new Object(type));
	return datas[datas.size() - 1]->get_id();
}
int Array::add_array(string key, string type)
{
	check_key(key);
	check_type(type);
	datas.push_back(new Array(type));
	return datas[datas.size() - 1]->get_id();
}