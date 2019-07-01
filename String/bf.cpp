#include<iostream>
#include<cstring>
using namespace std;

void bf(char *a, char *b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	for (int i = 0; i < len2; i++)
	{
		int k = i;
		int j = 0;
		for (j; j < len1; j++, k++)
		{
			if (b[k] != a[j])
				break;
		}
		if (j == len1)
			cout << "done " << i + 1 <<endl;
	}

}

int main()
{
	bf("abdcd", "abcdeabdcd");
	getchar();
	return 0;
}