#include<iostream>
using namespace std;

#define MAXSIZE 100

template <class DataType>
class seqList
{
public:
	seqList() { length = 0; }
	seqList(DataType a[], int n);
	~seqList() {}
	void printList();
	int Length() { return length; }
	DataType Get(int i);
	int Location(DataType val);
	void InsertVal(int i, DataType val);
	void Delate(int i);

private:
	int length;
	DataType data[MAXSIZE];
};

template<class DataType>
seqList<DataType>::seqList(DataType a[], int n)
{
	if (n > MAXSIZE)
		throw "para n is too big";
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	length = n;
}

template<class DataType>
void seqList<DataType>::printList()
{
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

template<class DataType> 
DataType seqList<DataType>::Get(int i)
{
	if (i < 0 || i > length)
		throw "para i out of scope";
	return data[i - 1];
}

template<class DataType>
int seqList<DataType>::Location(DataType val)
{
	int length_temp = 0;
	for (int i = 0; i < length; i++)
	{
		if (data[i] == val)
			return i + 1;
	}
	return 0;
}

template<class DataType>
void seqList<DataType>::InsertVal(int i, DataType val)
{
	if (i > length || i < 0)
		throw "insert location is wrong";
	for (int j = length - 1; j > i - 2; j--)
	{
		data[j + 1] = data[j];
	}
	data[i - 1] = val;
	length++;
}

template<class DataType>
void seqList<DataType>::Delate(int i)
{
	if (i < 0 || i > length)
		throw "delete location is wrong";
	for (int j = i - 1; j < length; j++)
	{
		data[j] = data[j + 1];
	}
	length--;
}

int main()
{
	int a[4] = { 1,2,3,4 };
	seqList<int> p(a, 4); 
	p.printList();
	cout << "the List length = "<< p.Length() <<endl;
	cout << "a[3] = " << p.Get(4) << endl;
	cout << "the location of 2 is in position " << p.Location(2) << endl;
	p.InsertVal(2, 1);
	p.printList();
	p.Delate(2);
	p.printList();
	getchar();
	return 0;
}