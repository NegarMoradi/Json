#include "JsonBuilder.hpp"
#include "Data.h"
#include "Exceptions.h"
#include "Object.h"
#include "String.h"
#include "Integer.h"
#include "Array.h"

#include <iostream>
#include <vector>
#include <string>   

#define ZERO 0
#define CURLY_BRACKET "{}"
#define L_CURLY "{"
#define R_CURLY "}"
#define COMMA ","
#define OBJECT "object"
#define ARRAY "array"

using namespace std;

JsonBuilder::JsonBuilder(){}
JsonBuilder::~JsonBuilder() {}
void JsonBuilder::addStringToObject(int parentId, string key, string value)
{
	if (parentId == ZERO)
	{
		check_key(key);
		datas.push_back(new String(key, value));
	}
	else
	{
		check = false;
		(find_parent_id_for_string(parentId, datas, key, value, OBJECT));
		if(check!=true)
			throw Invalid_id();
	}
}
void JsonBuilder::addIntegerToObject(int parentId, string key, int value)
{
	if (parentId == ZERO)
	{
		check_key(key);
		datas.push_back(new Integer(key, value));
	}
	else
	{
		check = false;
		find_parent_id_for_int(parentId, datas, key, value, OBJECT);
		if(check!=true)
			throw Invalid_id();
	}

}
int JsonBuilder::addContainerToObject(int parentId, string key, string type)
{
	if (parentId == ZERO)
	{
		check_key(key);
		check_type(type);
		if (type == OBJECT)
		{
			datas.push_back(new Object(key, type));
			return datas[datas.size() - 1]->get_id();
		}
		else if (type == ARRAY)
		{
			datas.push_back(new Array(key, type));
			return datas[datas.size() - 1]->get_id();
		}
	}
	else
	{
		flag = false;
		find_parent_id_for_container(parentId, datas, key, type, OBJECT);
		if (flag != true)
			throw Invalid_id();
		else
			return returning;
	}

}
void JsonBuilder::addStringToArray(int parentId, string value)
{
	check = false;
	find_parent_id_for_string(parentId, datas, NOT_HAVE, value, ARRAY);
	if(check!=true)
		throw Invalid_id();
}
void JsonBuilder::addIntegerToArray(int parentId, int value)
{
	check = false;
	find_parent_id_for_int(parentId, datas, NOT_HAVE, value, ARRAY);
	if (check != true)
		throw Invalid_id();
}
int JsonBuilder::addContainerToArray(int parentId, string type)
{
	check_type(type);
	flag = false;
	find_parent_id_for_container(parentId, datas, NOT_HAVE, type, ARRAY);
	if (flag != true)
		throw Invalid_id();
	else
		return returning;
}
void JsonBuilder::print(int id)
{
	if (id == ZERO)
	{
		print_for_root(id);
	}
	else 
	{
		check = false;
		find_id(id, datas);
		if (check!= true)
			throw Invalid_id();
	}
}
void JsonBuilder::print_for_root(int id)
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
bool JsonBuilder::find_id(int id, vector<Data*> all_datas)
{
	for (int i = 0; i< all_datas.size(); i++)
	{
		if (all_datas[i]->get_id() == id&&all_datas[i]->get_type() == OBJECT)
		{
			all_datas[i]->print(id);
			check = true;
			return true;
		}
		else
		{
			find_id(id, all_datas[i]->get_data());
		}
	}
}

bool JsonBuilder::find_parent_id_for_string(int id, vector<Data*> all_datas, string key, string value, string type)
{

	for (int i = 0; i< all_datas.size(); i++)
	{
		if (all_datas[i]->get_id() == id&&all_datas[i]->get_type() == type)
		{
			all_datas[i]->add_string(key, value);
			check = true;
			return true;
		}
		else
		{
			find_parent_id_for_string(id, all_datas[i]->get_data(), key, value, type);
		}
	}
}

bool JsonBuilder::find_parent_id_for_int(int id, vector<Data*> all_datas, string key, int value, string type)
{
	for (int i = 0; i< all_datas.size(); i++)
	{
		if (all_datas[i]->get_id() == id&&all_datas[i]->get_type() == type)
		{
			all_datas[i]->add_integer(key, value);
			check = true;
			return true;
		}
		else
		{
			find_parent_id_for_int(id, all_datas[i]->get_data(), key, value, type);
		}
	}
}

int JsonBuilder::find_parent_id_for_container(int id, vector<Data*> all_datas, string key, string type, string base_type)
{
	for (int i = 0; i< all_datas.size(); i++)
	{
		if (all_datas[i]->get_id() == id&&all_datas[i]->get_type() == base_type)
		{
			if (type == OBJECT)
			{
				returning = all_datas[i]->add_object(key, type);
				flag = true;
				return returning;
			}
			else if (type == ARRAY)
			{
				returning = all_datas[i]->add_array(key, type);
				flag = true;
				return returning;
			}
		}
		else
		{
			find_parent_id_for_container(id, all_datas[i]->get_data(), key, type, base_type);
		}
	}
}

void JsonBuilder::check_key(string key_)
{
	for (int i = 0; i<datas.size(); i++)
		if (datas[i]->has_same_key(key_))
			throw Duplicate_key();
}
void JsonBuilder::check_type(string type_)
{
	if (type_ != OBJECT && type_ != ARRAY)
		throw Undefinded_type();
}
