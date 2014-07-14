#ifndef QUEUETP_H
#define QUEUETP_H

template <class Item>
class QueueTP
{
private:
	enum {Q_SIZE = 10};
	class Node
	{
	public:
		Item item;
		Node *next;
		Node(const Item &i) : item(i), next(0) {}
	};
	Node *front;
	Node *rear;
	int items;
	const int qsize;
	QueueTP(const QueueTP &q) : qsize(0) {}
	QueueTP &operator=(const QueueTP &q) {return *this;}
public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool is_empty() const
	{
		return items == 0;
	}
	bool is_full() const
	{
		return items == qsize;
	}
	int queue_count() const
	{
		return items;
	}
	bool enqueue(const Item &item);
	bool dequeue(Item &item);
};

template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
	front = rear = 0;
	items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP()
{
	Node *temp;
	while(front != 0) {
	    temp = front;
	    front = front->next;
	    delete temp;
	}
}

template <class Item>
bool QueueTP<Item>::enqueue(const Item &item)
{
	if (is_full())
	{
		return false;
	}

	Node *add = new Node(item);
	items++;
	if (front == 0)
	{
		front = add;
	} else {
		rear->next = add;
	}
	rear = add;

	return true;
}

template <class Item>
bool QueueTP<Item>::dequeue(Item &item)
{
	if (is_empty())
	{
		return false;
	}

	item = front->item;
	items--;
	Node *temp = front;
	front = front->next;
	delete temp;
	if (is_empty())
	{
		rear = 0;
	}

	return true;
}

#endif // QUEUETP_H
