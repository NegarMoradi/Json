#include<string>
#include<vector>
#include<fstream>
#include<iostream>
class Channel;

class Robot
{
public:
	Robot();
	virtual void update(Channel*, std::string new_message) = 0;

protected:

};


class Echo :public Robot
{
public:
	Echo(std::string src, Channel* dest);
	void update(Channel* channel, std::string new_message) override;
private:
	std::string src_channel;
	Channel* dest_channel;
};

class Logger :public Robot
{
public:
	Logger(std::string file_);
	void update(Channel* channel, std::string new_message) override;
private:
	std::ofstream logger_file;
	std::string file_name;
};

class Fred :public Robot
{
public:
	Fred();
	void update(Channel* channel, std::string new_message) override;
};

class Librarian :public Robot
{
public:
	Librarian();
	int counter;
	void update(Channel* channel, std::string new_message) override;
};