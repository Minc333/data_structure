#include<iostream>
using namespace std;

template<class DataType>
struct Node
{
	DataType data;
	Node<DataType> *pFirstChild;
	Node<DataType> *pNextBrother;
	Node(DataType val)
	{
		data = val;
		pFirstChild = NULL;
		pNextBrother = NULL;
	}
};

template<class DataType>
class OrdinaryTree
{
public:
	OrdinaryTree();
	OrdinaryTree(DataType val);
	~OrdinaryTree();
	void Insert( DataType pFatherVal, DataType pSelfVal);
	void InsertBrother(Node<DataType> *pBrotherVal, DataType pSelfVal);
	Node<DataType>* Search(Node<DataType> *node, DataType val);
	void FreeMem(Node<DataType> *node);
	void Preorder(Node<DataType> *node);

	Node<DataType> *pRoot;

};

template<class DataType>
OrdinaryTree<DataType>::OrdinaryTree()
{
	pRoot = NULL;
}

template<class DataType>
OrdinaryTree<DataType>::OrdinaryTree(DataType val)
{
	pRoot = new Node<DataType>(val);
	if (pRoot == NULL)
		return;
}

template<class DataType>
OrdinaryTree<DataType>::~OrdinaryTree()
{
	if (pRoot == NULL)
		return;
	FreeMem(pRoot);
}

template<class DataType>
void OrdinaryTree<DataType>::Insert(DataType pFatherVal, DataType pSelfVal)
{
	if (pRoot == NULL)
		return;
	Node<DataType> *pFindNode = Search(pRoot, pFatherVal);
	if (pFindNode == NULL)
		return;
	if (pFindNode->pFirstChild == NULL)
	{
		pFindNode->pFirstChild = new Node<DataType>(pSelfVal);
		return;
	}
	else
	{
		InsertBrother(pFindNode->pFirstChild, pSelfVal);
		return;
	}
}

template<class DataType>
void OrdinaryTree<DataType>::InsertBrother(Node<DataType> *pBrotherVal, DataType pSelfVal)
{
	if (pBrotherVal->pNextBrother != NULL)
	{
		InsertBrother(pBrotherVal->pNextBrother, pSelfVal);
	}
	else
	{
		pBrotherVal->pNextBrother = new Node<DataType>(pSelfVal);
		return;
	}
}

template<class DataType>
Node<DataType>* OrdinaryTree<DataType>::Search(Node<DataType> *node, DataType val)
{
	if (node == NULL)
		return NULL;
	if (node->data = val)
		return node;
	if (node->pFirstChild == NULL && node->pNextBrother == NULL)
		return NULL;
	else
	{
		if (node->pFirstChild != NULL)
		{
			Node<DataType> *pTemp = Search(node->pFirstChild, val);
			if (pTemp != NULL)
				return pTemp;
			else
				return Search(node->pNextBrother, val);
		}
		else
			return Search(node->pNextBrother, val);
	}
}

template<class DataType>
void OrdinaryTree<DataType>::FreeMem(Node<DataType> *node)
{
	if (node == NULL)
		return;
	if (node->pFirstChild != NULL)
		FreeMem(node->pFirstChild);
	if (node->pNextBrother != NULL)
		FreeMem(node->pNextBrother);
	delete node;
	node = NULL;
}

template<class DataType>
void OrdinaryTree<DataType>::Preorder(Node<DataType> *node)
{
	if (node == NULL)
		return;
	cout << " " << node->data << " ";
	Preorder(node->pFirstChild);
	Preorder(node->pNextBrother);
}

int main()
{
	OrdinaryTree<int> Tree(10);
	Tree.Insert(1, 2);
	Tree.Insert(1, 3);
	Tree.Insert(2, 4);
	Tree.Preorder(Tree.pRoot);
	getchar();
	return 0;
}