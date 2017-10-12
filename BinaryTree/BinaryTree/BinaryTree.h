#pragma once

namespace TREE
{
	struct NODE
	{
		int data;
		NODE* left;
		NODE* right;
		NODE()
		{
			data = -1;
			left = nullptr;
			right = nullptr;
		}
	};
}

using namespace TREE;
class BinaryTree
{
	NODE* Root;
public:
	BinaryTree();
	~BinaryTree();

	void InsertData(int data);
	void DeleteData(int data);
	void Clear();
	bool IsEmpty() { return Root == nullptr ? true : false; }

	void PreOrder();
	void InOrder();
	void PostOrder();
	void BFS();
	void DFS();
private:
	void InsertData(NODE* newNode, NODE** curNode);
	bool SearchData(int data);
	NODE* SearchData(int data, NODE**& parentsPtr, NODE* curNode);
	void ClearData(NODE* curNode);

	void PreOrder(NODE* curNode);
	void InOrder(NODE* curNode);
	void PostOrder(NODE* curNode);
};

