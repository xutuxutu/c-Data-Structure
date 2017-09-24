#include "BinaryTree.h"
#include "Stack.h"

void main()
{
	BinaryTree bTree;
	STACK::Stack<int> stack;

	bTree.InsertData(10);
	bTree.InsertData(4);
	bTree.InsertData(15);
	bTree.InsertData(3);
	bTree.InsertData(1);
	bTree.InsertData(2);
	bTree.InsertData(6);
	bTree.InsertData(8);
	bTree.InsertData(5);

	bTree.DeleteData(4);

	bTree.BFS_Search();
}