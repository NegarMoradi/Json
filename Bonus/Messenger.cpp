#include"Messenger.h"
#include"Channel.h"
#include"Robot.h"
#include"Exceptions.h"
#include<iostream>
#include<vector>
#include<string>

#define ADD_CHANNEL "add_channel"
#define ADD_BOT "add_bot"
#define FRED "fred"
#define LIBRARIAN "librarian"
#define ECHO "echo"
#define LOGGER "logger"
#define TELL "tell"
#define ADD_CHANNEL "add_channel"

using namespace std;

Messenger::Messenger() {}

void Messenger::get_input()
{
	string command;
	while (	cin >> command)
	{
		if (command == ADD_CHANNEL)
			add_channel();
		else if (command == ADD_BOT)
			add_bot();
		else if (command == TELL)
			tell();
	}
}
void Messenger::add_bot()
{
	string bot_name;
	cin >> bot_name;
	if (bot_name == ECHO)
		add_bot_echo();
	else if (bot_name == LOGGER)
		add_bot_logger();
	else if (bot_name == LIBRARIAN)
		add_bot_librarian();
	else if (bot_name == FRED)
		add_bot_fred();
}
void Messenger::add_channel()
{
	string command, name;
	cin >> name;
	for (int i = 0; i < channels.size(); i++)
		if (channels[i]->name == name)
			throw Channel_exists();
	channels.push_back(new Channel(name));
}
void Messenger::add_bot_echo()
{
	string  src, dest;
	cin >> src >> dest;
	check_channel_exists(src);
	check_channel_exists(dest);
	check_same_channel(src, dest);
	add_echo(src, dest);
}
void Messenger::add_bot_fred()
{
	string channel_name;
	cin >> channel_name;
	check_channel_exists(channel_name);
	for (int i = 0; i < channels.size(); i++)
		if (channels[i]->name == channel_name)
			channels[i]->add_robot(new Fred());
}
void Messenger::add_bot_librarian()
{
	string channel_name;
	cin >> channel_name;
	check_channel_exists(channel_name);
	for (int i = 0; i < channels.size(); i++)
		if (channels[i]->name == channel_name)
			channels[i]->add_robot(new Librarian());
}
void Messenger::add_bot_logger()
{
	string  file_name;
	cin >>  file_name;
	add_logger(file_name);
}
void Messenger::tell()
{
	string channel_name, message;
	cin >> channel_name;
	getline(cin, message);
	message.erase(message.begin());
	check_channel_exists(channel_name);
	for (int i = 0; i < channels.size(); i++)
		if (channels[i]->name == channel_name)
			channels[i]->tell_channel(message);
}
void Messenger::add_logger(string file)
{
	for (int i = 0; i < channels.size(); i++)
		channels[i]->add_robot(new Logger(file));
}
void Messenger::check_same_channel(string src, string dest)
{
	if (src == dest)
		throw Same_channel();
}
void Messenger::add_echo(string src, string dest)
{
	for (int i = 0; i < channels.size(); i++)
		if (channels[i]->name == src)
			channels[i]->add_robot(new Echo(src, return_channel(dest)));
}
Channel* Messenger::return_channel(string name)
{
	for (int i = 0; i < channels.size(); i++)
		if (channels[i]->name == name)
			return channels[i];
}
void Messenger::check_channel_exists(string name_channel)
{
	bool check = false;
	for (int i = 0; i < channels.size(); i++)
		if (channels[i]->name == name_channel)
			check = true;
	if (check == false)
		throw Channel_does_not_exists();
}