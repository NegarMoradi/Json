#include"Exceptions.h"
using namespace std;

const char* Channel_exists::what() const throw() { return "Channel already exists\n"; }

const char* Channel_does_not_exists::what() const throw() { return "Channel does not exist\n"; }

const char* Same_channel::what() const throw() { return "Source and destination cannot be the same channel\n"; }