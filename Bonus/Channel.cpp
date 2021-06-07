#include"Channel.h"
#include"Robot.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

Channel::Channel(string name_)
{
	name = name_;
}
void Channel::add_robot(Robot* new_robot)
{
	robots.push_back(new_robot);
}
void Channel::notify(string message)
{
	for (int i = 0; i < robots.size(); i++)
		robots[i]->update(this,message);
}

void Channel::tell_channel(string message_)
{
	new_messege = message_;
	messages.push_back(message_);
	notify(new_messege);
}

void Channel::add_message(string message)
{
	messages.push_back(message);
	notify(message);
}