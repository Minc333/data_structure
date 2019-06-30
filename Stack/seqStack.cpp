#include<iostream>
using namespace std;

#define MAXSIZE 100

template<class T>
class seqStack
{
public:
	seqStack() { top = -1; }
	~seqStack() {}
	void push(T val);
	void printStack();
	void pop();
	T GetTop();
	void Empty();

private:
	T data[MAXSIZE];
	int top;
};

template<class T>
void seqStack<T>::push(T val)
{
	if (top >= MAXSIZE-1)
		throw "wrong";
	data[++top] = val;
}

template<class T>
void seqStack<T>::printStack()
{
	for (int i = 0; i < top + 1; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;

}

template<class T>
void seqStack<T>::pop()
{
	if (top == -1)
		throw "error";
	data[top--] = NULL;	
}

template<class T>
T seqStack<T>::GetTop()
{
	if (top == -1)
		throw "error";
	return data[top];
}

template<class T>
void seqStack<T>::Empty()
{
	if (top != -1)
	{
		for (int i = 0; i < top + 1; i++)
		{
			data[i] = NULL;
		}
	}
	top = -1;
		
}

int main()
{
	seqStack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.printStack();
	s.pop();
	s.printStack();
	cout << "the val of top is " << s.GetTop() << endl;
	s.Empty();
	s.printStack();
	s.push(7);
	s.printStack();
	getchar();
	return 0;
}