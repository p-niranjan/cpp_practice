#ifndef __TOPIC__
#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <mutex>
#include <string>
#include "Subscriber.h"

using subShPtr = std::shared_ptr<ISubscriber*>;

class Topic
{
private:
	string name;
	unordered_set<ISubscriber*> subscribers;
	std::mutex subMutex;
	
public:
	void addSubscriber(ISubscriber* sub)
	{
		std::lock_guard<std::mutex> lock(std::mutex);
		if(subscribers.find(sub) != subscribers.end()) {
			printf("Already subscribed!");
		} else {
			subscribers.insert(sub);
		}
	}
	
	void removeSubscriber(ISubscriber* sub)
	{
		std::lock_guard<std::mutex> lock(std::mutex);
		if(subscribers.find(sub) != subscribers.end()) {
			subscribers.erase(sub);
		} else {
			printf("Not subscribed!");
		}
	}
	
	void publish(Message msg) const
	{
		std::lock_guard<std::mutex> lock(std::mutex);
		for(auto sub : subscribers) {			
			sub->OnMsg(msg);
		}
	}
};
#endif
	