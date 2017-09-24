#include "BinaryTree.h"
#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;
BinaryTree::BinaryTree() : Root(nullptr)
{
}

BinaryTree::~BinaryTree()
{
}


void BinaryTree::InsertData(int data)
{
	NODE* newNode = new NODE();
	newNode->data = data;

	cout << "Insert Data : " << data << endl;
	if (Root == nullptr)
	{
		Root = newNode;
		cout << "InsertData : Root" << endl << endl;
	}
	else
		InsertData(newNode, &Root);
}

void BinaryTree::InsertData(NODE* newNode, NODE** curNode)
{
	NODE** nextNode;

	if (newNode->data < (*curNode)->data)
	{
		nextNode = &(*curNode)->left;
		cout << "Move Left" << endl;
	}
	else if (newNode->data >(*curNode)->data)
	{
		nextNode = &(*curNode)->right;
		cout << "Move Right" << endl;
	}

	if (*nextNode == nullptr)
	{
		*nextNode = newNode;
		cout << "Insert Data" << endl << endl;
	}
	else
	{
		InsertData(newNode, nextNode);
		cout << "Recursive" << endl;
	}
}

void BinaryTree::DeleteData(int data)
{
	if (Root == nullptr)
	{
		cout << "Tree is Empty" << endl;
		return;
	}

	NODE** parentsPtr = nullptr;
	NODE* targetNode = SearchData(data, parentsPtr, Root);

	//delete data is 
	//Last Node
	if (targetNode->left == nullptr && targetNode->right == nullptr)
		*parentsPtr = nullptr;
	//exist left Node
	else if (targetNode->right == nullptr)
		*parentsPtr = targetNode->left;
	//exist right Node
	else if (targetNode->left == nullptr)
		*parentsPtr = targetNode->right;
	//exist both Node
	else
	{
		//select rightNode.
		NODE** temp = &targetNode->right;
		//Find minimum Node
		while ((*temp)->left != nullptr)
			temp = &(*temp)->left;

		//minimum Node substitute Target Node
		(*temp)->left = targetNode->left;
		(*temp)->right = targetNode->right;
		*parentsPtr = *temp;
		*temp = nullptr;
	}

	delete targetNode;
}

NODE* BinaryTree::SearchData(int data, NODE**& parentsPtr, NODE* curNode)
{
	if (curNode->data == data)
		return curNode;

	else if (curNode->data < data)
		parentsPtr = &curNode->right;

	else if (curNode->data > data)
		parentsPtr = &curNode->left;

	SearchData(data, parentsPtr, *parentsPtr);
}

void BinaryTree::BFS_Search()
{
	QUEUE::Queue<NODE*> visitQueue;

	visitQueue.Enqueue(Root);

	NODE* curNode;
	while (!visitQueue.IsEmpty())
	{
		curNode = visitQueue.Dequeue();
		cout << curNode->data << " ";

		if (curNode->left)
			visitQueue.Enqueue(curNode->left);
		if (curNode->right)
			visitQueue.Enqueue(curNode->right);
	}
}

void BinaryTree::DFS_Search()
{
	STACK::Stack<NODE*> visitStack;

	visitStack.Push(Root);
	
	NODE* curNode;
	while (!visitStack.IsEmpty())
	{
		curNode = visitStack.Pop();
		cout << curNode->data << " ";

		if (curNode->right)
			visitStack.Push(curNode->right);
		if (curNode->left)
			visitStack.Push(curNode->left);
	}
}
