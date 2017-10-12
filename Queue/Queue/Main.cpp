#include "Queue.h"

void main()
{
	QUEUE::Queue<int> queue;

	queue.Enqueue(10);
	queue.Enqueue(1);
	queue.Enqueue(5);
	queue.Enqueue(3);
	queue.Enqueue(4);

	queue.Print();

	queue.Dequeue();
	queue.Dequeue();
	queue.Dequeue();

	queue.Print();
}