#ifndef QUEUE_H
#define QUEUE_H

class Customer
{
private:
	long arrive;
	int process_time;
public:
	Customer() { arrive = process_time = 0; }

	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return process_time; }
};

typedef Customer Item;

class Queue
{
private:
	struct Node
	{
		Item item;
		struct Node *next;
	};
	enum { Q_SIZE = 10 };

	Node *front;
	Node *rear;
	int items;
	const int qsize;

	Queue(const Queue &q) : qsize(0) {}
	Queue &operator=(const Queue &q) { return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();

	bool is_empty() const;
	bool is_full() const;
	int queue_count() const;
	bool enqueue(const Item &item);
	bool dequeue(Item &item);
};

#endif // QUEUE_H
