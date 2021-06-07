#include<string>
#include<vector>
 
class Channel;

class Messenger
{
public:
	Messenger();
	void get_input();
	void add_channel();
	void check_channel_exists(std::string name_channel);
	Channel* return_channel(std::string name);
	void add_bot();
	void add_bot_echo();
	void check_same_channel(std::string src, std::string dest);
	void add_echo(std::string src, std::string dest);
	void add_bot_logger();
	void add_logger(std::string file);
	void add_bot_fred();
	void add_bot_librarian();
	void tell();
private:
	std::vector<Channel*>channels;
};