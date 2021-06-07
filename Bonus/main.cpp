#include<iostream>
#include"Messenger.h"
#include"Exceptions.h"

using namespace std;

int main()
{
	Messenger new_messenger;
	try
	{
		new_messenger.get_input();
	}
	catch (const std::exception& exception)
	{
		cerr << exception.what();
	}
	
}