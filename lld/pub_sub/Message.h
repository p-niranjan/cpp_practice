#ifndef __MESSAGE__
#include <iostream>
#include <string>
using namespace std;

class Message
{
private:
	string content;
	
public:
	Message(const string& msg) : content(msg){}
	
	string getContent() const 
	{
		return this->content;
	}
};

#endif