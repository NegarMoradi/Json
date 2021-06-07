#ifndef DATA_H 
#define DATA_H "DATA_H"

#include<vector>
#include<string>
#include<memory>

class Data
{
public:
	Data(int _parent_id, std::string key_)noexcept 
	{
		parent_id = _parent_id;
		key = key_;
	}
	virtual void print(int id) = 0;
	virtual std::string get_type() const = 0;
	bool has_same_id(int _id) const;
	bool has_same_key(std::string key_);
	std::string get_key() { return key; }
	int get_id() { return parent_id; }
	virtual void add_string(std::string key, std::string value) = 0;
	virtual void add_integer(std::string key, int value) = 0;
	virtual int add_object(std::string key, std::string type) = 0;
	virtual int add_array(std::string key, std::string type) = 0;
	virtual std::vector<Data*>get_data()const = 0;
protected:
	static int next_id;
	int parent_id;
	std::string key;
	static int get_next_id() { return next_id++; }
};



#endif