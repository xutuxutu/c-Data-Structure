#include "Stack.h"

void main()
{
	STACK::Stack<int> stack;
	
	stack.Push(10);
	stack.Push(5);
	stack.Push(7);
	stack.Push(9);
	stack.Push(4);

	stack.Print();

	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();

	stack.Print();
}