#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node *next;
};

template<class T>
class LinkQueue
{
public:
	LinkQueue();
	~LinkQueue();
	void EnQueue(T val);
	T DeQueue();
	void PrintQueue();

private:
	Node<T> *front;
	Node<T> *rear;

};

template<class T>
LinkQueue<T>::LinkQueue()
{
	Node<T> *s = new Node<T>;
	s->next = NULL;
	front = rear = s;
}

template<class T>
LinkQueue<T>::~LinkQueue()
{
	if (front != rear)
	{
		Node<T> *p = front;
		front = front->next;
		delete p;
	}
}

template<class T>
void LinkQueue<T>::EnQueue(T val)
{
	Node<T> *s = new Node<T>;
	s->data = val;
	s->next = NULL;
	rear->next = s;
	rear = s;
}

template<class T>
void LinkQueue<T>::PrintQueue()
{
	if (front == rear)
		throw "error";
	Node<T> *p = front ->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template<class T>
T LinkQueue<T>::DeQueue()
{
	if (front == rear)
		throw "ERROR";
	return front->next->data;
	Node<T> *p = front ->next;
	front = front->next->next;
	delete p;
	
}

int main()
{
	LinkQueue<int> q;
	q.EnQueue(1);
	q.EnQueue(2);
	q.EnQueue(3);
	q.PrintQueue();
	cout << q.DeQueue() << endl;
	q.PrintQueue();
	getchar();
	return 0;
}