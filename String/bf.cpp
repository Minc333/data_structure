#include<iostream>
using namespace std;

int bf(char *s, char *p)
{
	int slen = strlen(s);
	int plen = strlen(p);
	int i = 0; 
	int j = 0;
	while (i < slen && j < plen)
	{
		if (s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == plen)
		return i-j+1;
	else
		return -1;
}

int main()
{
	int k = bf("ABCABCDE", "ABCD");
	cout << k << endl;
	getchar();
	return 0;
}