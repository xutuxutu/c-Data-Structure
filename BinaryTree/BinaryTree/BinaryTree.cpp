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
	Clear();
}


void BinaryTree::InsertData(int data)
{
	NODE* newNode = new NODE();
	newNode->data = data;

	cout << "Insert Data : " << data << endl;
	if (IsEmpty())
		Root = newNode;
	else
	{
		if (!SearchData(data))
			InsertData(newNode, &Root);
		else
			cout << "Data is alread exist" << endl;
	}
}

void BinaryTree::InsertData(NODE* newNode, NODE** curNode)
{
	NODE** nextNode;

	if (newNode->data < (*curNode)->data)
		nextNode = &(*curNode)->left;
	else if (newNode->data >(*curNode)->data)
		nextNode = &(*curNode)->right;

	if (*nextNode == nullptr)
		*nextNode = newNode;
	else
		InsertData(newNode, nextNode);
}

void BinaryTree::DeleteData(int data)
{
	if (IsEmpty())
	{
		cout << "Tree is Empty" << endl;
		return;
	}

	NODE** parentsPtr = nullptr;
	NODE* targetNode = SearchData(data, parentsPtr, Root);
	if (targetNode == nullptr)
	{
		cout << "Data not exist" << endl;
		return;
	}

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
		if (targetNode->right->data == (*temp)->data)
			(*temp)->right = nullptr;
		else
			(*temp)->right = targetNode->right;
		*parentsPtr = *temp;
		*temp = nullptr;
	}

	delete targetNode;
}

void BinaryTree::Clear()
{
	if (IsEmpty())
		return;

	ClearData(Root);
}

void BinaryTree::ClearData(NODE* curNode)
{
	if (curNode->left != nullptr)
		ClearData(curNode->left);

	if (curNode->right != nullptr)
		ClearData(curNode->right);

	delete curNode;
}

bool BinaryTree::SearchData(int data)
{
	return false;
}

NODE* BinaryTree::SearchData(int data, NODE**& parentsPtr, NODE* curNode)
{
	if (curNode == nullptr)
		return nullptr;

	if (curNode->data == data)
		return curNode;

	else if (curNode->data < data)
		parentsPtr = &curNode->right;

	else if (curNode->data > data)
		parentsPtr = &curNode->left;

	SearchData(data, parentsPtr, *parentsPtr);
}

void BinaryTree::PreOrder()
{
	if (!IsEmpty())
	{
		PreOrder(Root);
		cout << endl;
	}
}

void BinaryTree::PreOrder(NODE* curNode)
{
	cout << curNode->data << " ";

	if (curNode->left != nullptr)
		PreOrder(curNode->left);
	if (curNode->right != nullptr)
		PreOrder(curNode->right);
}

void BinaryTree::InOrder()
{
	if (!IsEmpty())
	{
		InOrder(Root);
		cout << endl;
	}
}

void BinaryTree::InOrder(NODE* curNode)
{
	if (curNode->left != nullptr)
		InOrder(curNode->left);

	cout << curNode->data << " ";

	if (curNode->right != nullptr)
		InOrder(curNode->right);
}

void BinaryTree::PostOrder()
{
	if (!IsEmpty())
	{
		PostOrder(Root);
		cout << endl;
	}
}

void BinaryTree::PostOrder(NODE* curNode)
{
	if (curNode->left != nullptr)
		InOrder(curNode->left);
	if (curNode->right != nullptr)
		InOrder(curNode->right);

	cout << curNode->data << " ";
}

void BinaryTree::BFS()
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

void BinaryTree::DFS()
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
