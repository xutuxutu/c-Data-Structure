#pragma once
#include <iostream>

using namespace std;
namespace STACK
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
	class Stack
	{
	private:
		NODE<T>* Head;
	public:
		Stack() : Head(nullptr) {}
		~Stack() { Clear(); }

		void Push(T data);
		T Pop();
		void Clear();
		bool IsEmpty() { return Head == nullptr ? true : false; }

		void Print();
	};

	template <typename T>
	void Stack<T>::Push(T data)
	{
		NODE<T>* newNode = new NODE<T>;
		newNode->data = data;

		NODE<T>* next = Head;
		Head = newNode;
		newNode->next = next;
	}

	template <typename T>
	T Stack<T>::Pop()
	{
		if (IsEmpty())
		{
			cout << "Stack is Empty" << endl;
			return 0;
		}

		T data;

		NODE<T>* target = Head;
		Head = target->next;
		data = target->data;
		delete target;

		return data;
	}

	template <typename T>
	void Stack<T>::Clear()
	{
		if (IsEmpty())
		{
			cout << "Stack is Empty" << endl;
			return;
		}

		NODE<T>* target;
		while (Head != nullptr)
		{
			target = Head;
			Head = Head->next;
			delete target;
		}
	}

	template <typename T>
	void Stack<T>::Print()
	{
		if (IsEmpty())
		{
			cout << "Stack is Empty" << endl;
		}

		NODE<T>* next = Head;
		while (next != nullptr)
		{
			cout << next->data << " ";
			next = next->next;
		}
		cout << endl;
	}
}