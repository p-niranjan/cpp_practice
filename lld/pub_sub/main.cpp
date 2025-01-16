#include "Subscriber.h"
#include "Message.h"
#include "Publisher.h"
#include "Topic.h"

int main()
{
	Publisher p1, p2;
	Topic* t1 = new Topic;
	Topic* t2 = new Topic;
	
	ISubscriberInterface* sub = new ConsoleSubscriber;
	t1->addSubscriber(sub);
	t2->addSubscriber(sub);

	p1.registerTopic(t2);
	p2.registerTopic(t1);
	
	Message m1("m1 msg");
	Message m2("m2 msg");
	
	p1.publish(t1, m2);
	p2.publish(t2, m1);
	
	delete t1; t1 = nullptr;
	delete t2; t2 = nullptr;
}