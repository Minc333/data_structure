#include<iostream>
using namespace std;

template<class DataType>
struct BTNode
{
	DataType data;
	BTNode<DataType> *lchild;
	BTNode<DataType> *rchild;
	BTNode<DataType>(DataType val)
	{
		data = val;
		lchild = NULL;
		rchild = NULL;
	}
};

template<class DataType>
class BiTree
{
public:
	BiTree();
	BiTree(DataType val);
	~BiTree();
	void FreeMem(BTNode<DataType> *node);
	void PreTraversal(BTNode<DataType> *node);
	void InTraversal(BTNode<DataType> *node);
	void PosTraversal(BTNode<DataType> *node);
	void Insert(DataType parent, DataType lchild, DataType rchild);
	BTNode<DataType> *Search(BTNode<DataType> *node, DataType val);

public:
	BTNode<DataType> *pRoot;

};

template<class DataType>
BiTree<DataType>::BiTree()
{
	pRoot = NULL;
}

template<class DataType>
BiTree<DataType>::BiTree(DataType val)
{
	pRoot = new BTNode<DataType>(val);
}

template<class DataType>
BiTree<DataType>::~BiTree()
{
	if (pRoot == NULL)
		return;
	FreeMem(pRoot);
}

template<class DataType>
void BiTree<DataType>::FreeMem(BTNode<DataType> *node)
{
	if (node == NULL)
		return;
	if (node->lchild)
		FreeMem(node->lchild);
	if (node->rchild)
		FreeMem(node->rchild);
	delete node;
	node = NULL;
}

template<class DataType>
void BiTree<DataType>::PreTraversal(BTNode<DataType> *node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	PreTraversal(node->lchild);
	PreTraversal(node->rchild);
}

template<class DataType>
void BiTree<DataType>::InTraversal(BTNode<DataType> *node)
{
	if (!node)
		return;
	if (node->lchild)
		InTraversal(node->lchild);
	cout << node->data << " ";
	if (node->rchild)
		InTraversal(node->rchild);
}

template<class DataType>
void BiTree<DataType>::PosTraversal(BTNode<DataType> *node)
{
	if (!node)
		return;
	if (node->lchild)
		PosTraversal(node->lchild);
	if (node->rchild)
		PosTraversal(node->rchild);
	cout << node->data << " ";
}

template<class DataType>
void BiTree<DataType>::Insert(DataType parent, DataType lchildval, DataType rchildval)
{
	BTNode<DataType> *node = Search(pRoot, parent);
	if (node == NULL)
		return;
	if (node->lchild != NULL)
	{
		cout << "lchild of node " << node->data << " : " << node->lchild->data << " -> " << lchildval << endl;
		node->lchild->data = lchildval;
	}
	else
	{
		node->lchild = new BTNode<DataType>(lchildval);
	}
	if (node->rchild != NULL)
	{
		cout << "rchild of node " << node->data << " : " << node->rchild->data << " -> " << rchildval << endl;
		node->rchild->data = rchildval;
	}
	else
	{
		node->rchild = new BTNode<DataType>(rchildval);
	}
}

template<class DataType>
BTNode<DataType> *BiTree<DataType>::Search(BTNode<DataType> *node, DataType val)
{
	if (node == NULL)
		return NULL;
	if (node->data == val)
		return node;
	BTNode<DataType> *pTemp =NULL;
	if (node->lchild != NULL)
	{
		pTemp = Search(node->lchild, val);
		if (pTemp)
			return pTemp;
	}
	if (node->rchild != NULL)
	{
		pTemp = Search(node->rchild, val);
		if (pTemp)
			return pTemp;
	}
	else
		
		return pTemp;
}

int main()
{
	BiTree<int> b(1);
	b.Insert(1, 2, 3);
	b.Insert(2, 4, 5);
	b.Insert(3, 6, 7);
	cout << "Preorder Traversal: ";
	b.PreTraversal(b.pRoot);
	cout << endl;
	cout << "Intermediate Traversal: ";
	b.InTraversal(b.pRoot);
	cout << endl;
	cout << "Postorder Traversal: ";
	b.PosTraversal(b.pRoot);
	cout << endl;
	getchar();
	return 0;
}