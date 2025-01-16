#ifndef __SUBSCRIBER__

#include <iostream>
#include "Message.h"

class ISubscriberInterface
{
public:
	virtual void OnMsg(Message msg) = 0;
};

class ConsoleSubscriber : public ISubscriberInterface
{
public:
	void OnMsg(Message msg) 
	{
		cout << "Console message: " << msg.getContent() << endl;
	}
};
#endif