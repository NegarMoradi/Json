#ifndef OBJECT_H
#define OBJECT_H "OBJECT_H"

#include "Data.h"
#include <memory>
#include <string>
#include <vector>
#define NOT_HAVE "not_have"
#define OBJECT "object"
class Object :public Data
{
public:
	Object(std::string key_, std::string type_)noexcept 
		: Data(get_next_id(), key_)
	{
		key = key_;
		type = type_;
	}
	Object(std::string type_)
		:Data(get_next_id(), NOT_HAVE)
	{
		type = type_;
		key = NOT_HAVE;
	}
	virtual void print(int id) override;
	void print_object(int id);
	virtual std::string get_type() const override{ return OBJECT; }
	void add_string(std::string key, std::string value);
	void add_integer(std::string key, int value);
	int add_object(std::string key, std::string type);
	int add_array(std::string key, std::string type);
	void check_type(std::string type_);
	void check_key(std::string key_);
	void print_for_big_data(int id);
	void print_for_data_one(int id);
	virtual std::vector<Data*>get_data()const override { return datas; }
private:
	std::vector<Data*> datas;
	std::string key;
	std::string type;
};


#endif