#include "Object.h"
#include "Exceptions.h"
#include "String.h"
#include "Integer.h"
#include "Array.h"
#include "Data.h"

#include <iostream>
#include <vector>
#include <string>

#define TAB "    "
#define QUOTATION "\""
#define COLON ": "
#define ZERO 0
#define ONE 1
#define CURLY_BRACKET "{}"
#define L_CURLY "{"
#define R_CURLY "}"
#define COMMA ","
#define OBJECT "object"
#define ARRAY "array"

using namespace std;

void Object::check_type(string type_)
{
	if (type_ != OBJECT && type_ != ARRAY)
		throw Undefinded_type();
}

void Object::check_key(string key_)
{
	for (int i = 0; i<datas.size(); i++)
		if (datas[i]->has_same_key(key_))
			throw Duplicate_key();
}

void Object::print(int id)
{
	if (id == parent_id)
		print_object(id);
	else
	{
		if (key != NOT_HAVE)
		{
			if (datas.size() == ZERO)
				cout << TAB << QUOTATION << key << QUOTATION << COLON << CURLY_BRACKET;
			else
			{
				cout << TAB << QUOTATION << key << QUOTATION << COLON << L_CURLY << endl;
				print_for_big_data(id);
			}
		}
		else
		{
			if (datas.size() == ZERO)
				cout << TAB << CURLY_BRACKET;
			else
			{
				cout << TAB << L_CURLY << endl;
				print_for_big_data(id);
			}
		}

	}
	
}
void Object::print_object(int id)
{
	if (datas.size() == ZERO)
		cout << CURLY_BRACKET << endl;
	else
	{
		cout << L_CURLY << endl;
		for (int i = 0; i < datas.size() - 1; i++)
		{
			datas[i]->print(id);
			cout << COMMA << endl;
		}
		datas[datas.size() - 1]->print(id);
		cout << endl;
		cout << R_CURLY << endl;
	}
}
void Object::print_for_big_data(int id)
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
		cout << TAB << R_CURLY;
	}
	else if (datas.size() == ONE)
		print_for_data_one(id);
}
void Object::print_for_data_one(int id)
{
	cout << TAB;
	datas[datas.size() - 1]->print(id);
	cout << endl;
	cout << TAB << R_CURLY;
}
void Object::add_string(string key, string value)
{
	check_key(key);
	datas.push_back(new String(key, value));
}
void Object::add_integer(string key, int value)
{
	check_key(key);
	datas.push_back(new Integer(key, value));
}

int Object::add_object(string key, string type)
{
	check_key(key);
	check_type(type);
	datas.push_back(new	Object(key, type));
	return datas[datas.size() - 1]->get_id();
}
int Object::add_array(string key, string type)
{
	check_key(key);
	check_type(type);
	datas.push_back(new Array(key, type));
	return datas[datas.size() - 1]->get_id();
}