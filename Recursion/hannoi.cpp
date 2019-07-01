#include <iostream>

using namespace std;

void TowersofHanoi(int n, char x, char y, char z)
{

	if (n)
	{
		TowersofHanoi(n - 1, x, z, y);//将n-1个盘子从x移动到z
		cout << "From " << x << "To " << y << endl;//将第n个盘子移动到y
		TowersofHanoi(n - 1, z, y, x);//将z上的盘子移动到y
	}
}

int main()
{
	TowersofHanoi(10, 'A', 'B', 'C');
	getchar();
	return 0;
}
