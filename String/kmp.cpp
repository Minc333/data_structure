#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getNext(string T)
{
	vector<int> next(T.size(), 0);            
	next[0] = -1;                           
	int k = -1;
	int j = 0;
	while (j < T.size() - 1)
	{
		if (k == -1 || T[j] == T[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
	return next;                            // ·µ»Ønext¾ØÕó
}

int KMP(string S, string T)
{
	vector<int> next = getNext(T);
	int i = 0, j = 0;
	while (S[i] != '\0' && T[j] != '\0')
	{
		if (S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
		if (j == -1)
		{
			++i;
			++j;
		}
	}
	if (T[j] == '\0')
		return i - j;
	else
		return -1;
}

int main()
{
	string S = "ababaababcb";
	string T = "ababc";
	int num = KMP(S, T);
	cout << num;
	getchar();
	return 0;
}