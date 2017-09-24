#pragma once
#include <iostream>

using namespace std;
namespace QUEUE
{
	template <typename T>
	struct NODE
	{
		T data;
		NODE<T>* next;
		NODE<T>()
		{
			data = 0;
			next = nullptr;
		}
	};

	template <typename T>
	class Queue
	{
	private:
		NODE<T>* Head;
		NODE<T>* Tail;
	public:
		Queue() : Head(nullptr), Tail(nullptr) { }
		~Queue() { Clear(); }

		void Enqueue(T data);
		T Dequeue();
		void Clear();

		void Print();
		bool IsEmpty() { return Head == nullptr ? true : false; }
	};

	template <typename T>
	void Queue<T>::Enqueue(T data)
	{
		NODE<T>* newNode = new NODE<T>;
		newNode->data = data;

		if (IsEmpty())
		{
			Tail = Head = newNode;
			return;
		}

		Tail->next = newNode;
		Tail = newNode;
	}

	template <typename T>
	T Queue<T>::Dequeue()
	{
		if (IsEmpty())
		{
			cout << "Queue is Empty" << endl;
			return 0;
		}

		NODE<T>* temp = Head;
		T data = temp->data;

		if (Head->next == nullptr)
		{
			Head = nullptr;
			Tail = nullptr;
		}
		else
			Head = Head->next;

		delete temp;

		return data;
	}

	template <typename T>
	void Queue<T>::Clear()
	{
		if (IsEmpty())
		{
			cout << "Queue is Empty" << endl;
			return;
		}

		NODE<T>* temp;
		while (Head->next != nullptr)
		{
			temp = Head;
			Head = Head->next;
			delete temp;
		}

		Head = nullptr;
		Tail = nullptr;
	}

	template <typename T>
	void Queue<T>::Print()
	{
		if (IsEmpty())
		{
			cout << "Queue is Empty" << endl;
			return;
		}

		NODE<T>* temp = Head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}


