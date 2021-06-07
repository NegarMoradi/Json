#include"Robot.h"
#include"Channel.h"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

#define FIVE 5
#define HI "Hi"
#define HELLO "Hello"
#define QUIET "Quiet!"

using namespace std;

Robot::Robot(){}

Logger::Logger(string file_)
	:logger_file(file_,std::ofstream::app)
{
	file_name = file_;
}
void Logger::update(Channel* channel, std::string new_message)
{
	logger_file << new_message << endl;
}

Echo::Echo(string src, Channel* dest)
{
	src_channel = src;
	dest_channel = dest;
}
void Echo::update(Channel* channel, std::string new_message)
{
	dest_channel->add_message(new_message);
}
Fred::Fred(){}

void Fred::update(Channel* channel, std::string new_message)
{
	if (new_message == HI)
		channel->add_message(HELLO);
}
Librarian::Librarian() { counter = 0; }

void Librarian::update(Channel* channel, std::string new_message)
{
	counter++;
	if (counter == FIVE)
	{
		channel->add_message(QUIET);
		counter = 0;
	}
}