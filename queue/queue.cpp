#include <cstdlib>
#include "queue.h"

Queue::Queue(int qs) : qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

Queue::~Queue()
{
	Node * temp;
	while(front != nullptr) {
	    temp = front;
	    front = front->next;
	    delete temp;
	}
}

bool Queue::is_empty() const
{
	return items == 0;
}

bool Queue::is_full() const
{
	return items == qsize;
}

int Queue::queue_count() const
{
	return items;
}

bool Queue::enqueue(const Item &item)
{
	if (is_full())
	{
		return false;
	}

	Node *add = new Node;
	add->item = item;
	add->next = nullptr;
	items++;
	if (front == nullptr)
	{
		front == add;
	} else {
		rear->next = add;
	}
	rear = add;

	return true;
}

bool Queue::dequeue(Item &item)
{
	if (front == nullptr)
	{
		return false;
	}
	item = front->item;
	items--;
	Node *temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
	{
		rear = nullptr;
	}

	return true;
}

void Customer::set(long when)
{
	process_time = std::rand() % 3 + 1;
	arrive = when;
}