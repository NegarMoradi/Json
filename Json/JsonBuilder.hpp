#ifndef __JSON_BUILDER_H__
#define __JSON_BUILDER_H__

#include <memory>
#include <string>
#include <vector>

class Data;

class JsonBuilder
{
public:
	JsonBuilder();
	~JsonBuilder();
	void addStringToObject(int parentId, std::string key, std::string value);
	void addIntegerToObject(int parentId, std::string key, int value);
	int addContainerToObject(int parentId, std::string key, std::string type);
	void addStringToArray(int parentId, std::string value);
	void addIntegerToArray(int parentId, int value);
	int addContainerToArray(int parentId, std::string type);
	void print(int id);
	void print_for_root(int id);
	bool find_id(int id, std::vector<Data*> all_datas);
	void check_key(std::string key_);
	void check_type(std::string type_);
	bool find_parent_id_for_string(int id, std::vector<Data*> all_datas, std::string key, std::string value, std::string type);
	bool find_parent_id_for_int(int id, std::vector<Data*> all_datas, std::string key, int value, std::string type);
	int find_parent_id_for_container(int id, std::vector<Data*> all_datas, std::string key, std::string type, std::string base_type);
	bool flag;
	bool check;
	int returning;
private:
	std::vector<Data*> datas;

};

#endif 