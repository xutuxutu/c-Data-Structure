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

	void BFS_Search();
	void DFS_Search();
private:
	void InsertData(NODE* newNode, NODE** curNode);
	NODE* SearchData(int data, NODE**& parentsPtr, NODE* curNode);
};

