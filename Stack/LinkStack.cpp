#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node<T> *next;
};

template<class T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
	void Pop(T val);
	void Push();
	void printStack();
	void Empty();
	T Gettop() { if (top) return top->next->data; }

private:
	Node<T> *top;

};

template<class T>
LinkStack<T>::LinkStack()
{
	top = new Node<T>;
	top ->next = NULL;
}

template<class T>
LinkStack<T>::~LinkStack()
{
	while (top)
	{
		Node<T> *p = top;
		top = top ->next;
		delete p;
	}
}

template<class T>
void LinkStack<T>::Pop(T val)
{
	Node<T> *p = new Node<T>;
	p->data = val;
	p->next = top->next;
	top->next = p;
}

template<class T>
void LinkStack<T>::printStack()
{
	Node<T> *p = top->next;
	while (p)
	{
		cout << p->data << endl;
		p = p->next;
	}
	cout << endl;
}

template<class T>
void LinkStack<T>::Push()
{
	if (!top)
		throw "error";
	Node<T> *p = top;
	top = top->next;
	delete p;
}

template<class T>
void LinkStack<T>::Empty()
{
	while (top)
	{
		Node<T> *p = top;
		top = top->next;
		delete p;
	}
}



int main()
{
	LinkStack<int> s;
	s.Pop(1);
	s.Pop(2);
	s.Pop(3);
	s.printStack();
	s.Push();
	s.printStack();
	cout << s.Gettop() << endl;
	s.Empty();
	getchar();
	return 0;
}