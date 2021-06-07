#ifndef ARRAY_H
#define ARRAY_H "ARRAY_H"

#include "Data.h"
#include <memory>
#include <vector>
#include <string>
#define NOT_HAVE "not_have"
#define ARRAY "array"
class Array :public Data
{
public:
	Array(std::string key_, std::string type_)noexcept
		: Data(get_next_id(), key_)
	{
		key = key_;
		type = type_;
	}
	Array(std::string type_)
		:Data(get_next_id(), NOT_HAVE)
	{
		key = NOT_HAVE;
		type = type_;
	}
	virtual void print(int id) override;
	virtual std::string get_type() const override{return ARRAY;}
	void check_type(std::string type_);
	void check_key(std::string key_);
	void add_string(std::string key, std::string value);
	void add_integer(std::string key, int value);
	int add_object(std::string key, std::string type);
	int add_array(std::string key, std::string type);
	void print_for_big_data(int id);
	void print_for_data_one(int id);
	virtual std::vector<Data*>get_data()const override { return datas; }
private:
	std::vector<Data*> datas;
	std::string key;
	std::string type;
};

#endif