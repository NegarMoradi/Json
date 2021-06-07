#include<string>
#include<vector>

class Robot;

class Channel
{
public:
	Channel(std::string name_);
	std::string name;
	void notify(std::string message);
	void add_message(std::string message);
	void add_robot(Robot* new_robot);
	void tell_channel(std::string message_);
	bool check;
private:
	std::string new_messege;
	std::vector<std::string>messages;
	std::vector<Robot*>robots;

};