#ifndef INTEGER_H
#define INTEGER_H "INTEGER_H"

#include <string>
#include "Data.h"
#define NOT_HAVE "not_have"
#define INTEGER "integer"

class Integer :public Data
{
public:
	Integer(std::string key_, int value_)noexcept	
		:Data(get_next_id(), key_)
	{
		key = key_;
		value = value_;
	}

	Integer(int value_) :Data(get_next_id(), NOT_HAVE)
	{
		key = NOT_HAVE;
		value = value_;
	}
	virtual std::string get_type() const override {return INTEGER;}
	virtual void print(int id) override;
	virtual std::vector<Data*>get_data()const override { return datas; }
	void add_string(std::string key, std::string value) { ; }
	void add_integer(std::string key, int value) { ; }
	int add_object(std::string key, std::string type) { return -1; }
	int add_array(std::string key, std::string type) { return -1; }

private:
	int value;
	std::string key;
	std::vector<Data*> datas;
};


#endif