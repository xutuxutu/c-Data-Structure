#include "BinaryTree.h"
#include "Stack.h"

void main()
{
	BinaryTree bTree;
	STACK::Stack<int> stack;

	bTree.InsertData(8);
	bTree.InsertData(5);
	bTree.InsertData(14);
	bTree.InsertData(3);
	bTree.InsertData(7);
	bTree.InsertData(10);
	bTree.InsertData(16);

	bTree.DFS();
	bTree.PreOrder();
	bTree.InOrder();
	bTree.PostOrder();
	bTree.BFS();
}