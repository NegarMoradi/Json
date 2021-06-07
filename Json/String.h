#ifndef STRING_H
#define STRING_H "STRING_H"

#include "Data.h"
#define ARRAY "array"
#define NOT_HAVE "not_have"
#define STRING "string"

class String :public Data
{
public:
	String(std::string key_, std::string value_)noexcept
		:Data(get_next_id(), key_)
	{
		key = key_;
		value = value_;
	}
	String(std::string value_)noexcept 
		: Data(get_next_id(), NOT_HAVE)
	{
		key = NOT_HAVE;
		value = value_;
	}
	virtual void print(int id) override;
	virtual std::string get_type() const override{ return STRING; }
	virtual std::vector<Data*>get_data()const override { return datas; }
	void add_string(std::string key, std::string value) { ; }
	void add_integer(std::string key, int value) { ; }
	int add_object(std::string key, std::string type) { return -1; }
	int add_array(std::string key, std::string type) { return -1; }

private:
	std::string value;
	std::string key;
	std::vector<Data*> datas;
};

#endif