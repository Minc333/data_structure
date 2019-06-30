#include<iostream>
using namespace std;

template<class DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;
};

template<class DataType>
class LinkList
{
public:
	LinkList();
	LinkList(DataType a[], int n);
	~LinkList();
	void Insert(int i, DataType val);
	void printList();
	int Length();
	DataType GetElem(int i);
	int Location(DataType val);
	void Delete(int i);

private:
	Node<DataType> *first;
	int length;

};

template<class DataType>
LinkList<DataType>::LinkList()
{
	first = new Node<DataType>;
	first->next = NULL;
	length = 0;
}

template<class DataType>
LinkList<DataType>::LinkList(DataType a[], int n)
{
	first = new Node<DataType>;
	first->next = NULL;
	length = n;
	for (int i = 0; i < n; i++)
	{
		Node<DataType> *s = new Node<DataType>;
		s ->data = a[i];
		s->next = first->next;
		first->next = s;

	}
}

template<class DataType>
LinkList<DataType>::~LinkList()
{
	while (first)
	{
		Node<DataType> *q = first;
		first = first->next;
		delete q;
	}
}

template<class DataType>
void LinkList<DataType>::Insert(int i, DataType val)
{
	if (i < 0 || i > length)
		throw "wrong";
	Node<DataType> *p = first;
	int count = 0;
	while (p && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (!p)
		throw "wrong";
	else
	{
		Node<DataType> *s = new Node<DataType>;
		s->next = p -> next;
		p->next = s;
		s->data = val;
		length++;
	}
}

template<class DataType>
void LinkList<DataType>::printList()
{
	Node<DataType> *p = first -> next;
	while( p )
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template<class DataType>
int LinkList<DataType>::Length()
{
	return length;
}

template<class DataType>
DataType LinkList<DataType>::GetElem( int i )
{
	if (i < 0 || i > length)
		throw "wrong";
	Node<DataType> *p = first;
	int count = 0;
	while (p && count < i)
	{
		p = p->next;
		count++;
	}
	if (count == i || p)
	{
		return p->data;
	}
	return 0;
}

template<class DataType>
int LinkList<DataType>::Location(DataType val)
{
	Node<DataType> *p = first->next;
	int count = 1;
	while (p && p->data != val)
	{
		p = p -> next;
		count++;
	}
	return count;
}

template<class DataType>
void LinkList<DataType>::Delete(int i)
{
	if (i < 0 || i > length)
		throw "wrong";
	Node<DataType> *p = first->next;
	int count = 1;
	while (p && count < i-1)
	{
		p = p->next;
		count++;
	}
	if (count == i-1 || p)
	{
		p->next = p->next->next;
	}
	length--;
}

int main()
{
	int a[] = { 1,2,3,4 };
	LinkList<int> p(a, 4);
	p.printList();
	cout << "the length of list is " << p.Length() << endl;
	p.Insert(2, 5);
	p.printList();
	cout << "the length of list is " << p.Length() << endl;
	cout << "the val of 3 is " << p.GetElem(3) << endl;
	cout << "the location of 4 is " << p.Location(4) << endl;
	p.Delete(4);
	p.printList();
	cout << "the length of list is " << p.Length() << endl;
	getchar();
	return 0;
}