#ifndef __PUBLISHER__
#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <mutex>
#include <string>
#include "Topic.h"

class Publisher
{
private:
	std::unordered_set<Topic*> topics;
	std::mutex topicMutex;
	
public:
	void registerTopic(Topic* topic)
	{
		std::lock_guard<std::mutex> lock;
		topics.insert(topic);
	}
	
	void Publish(Topic topic, Message msg) const
	{
		std::lock_guard<std::mutex> lock;
		auto it = topics.find(topic);
		if(it != topics.end())
		{
			it->Publish(msg);
			return;
		}
		printf("Topic not registered\n");
	}

#endif