#include "Data.h"


#include <iostream>
#include <vector>
#include <string>
#define ONE 1
#define ZERO 0
#define NOT_HAVE "not_have"
using namespace std;


int Data::next_id = ONE;

bool Data::has_same_id(int _id) const
{
	return parent_id == _id;
}

bool Data::has_same_key(string key_)
{
	if (key_ == NOT_HAVE)
		return false;
	else
		return key == key_;
}
