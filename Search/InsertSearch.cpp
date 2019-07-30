#include<iostream>
#include<vector>
using namespace std;

int InsertSearch(vector<int> a, int value)
{
	int low = 0;
	int high = a.size() - 1;
	while (low <= high)
	{
		int mid = low + (value - a[low])/(a[high]-a[low])*(high - low);
		if (a[mid] == value)
			return mid;
		else if (a[mid] > value)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main()
{
	vector<int> a = { 1,2,3,4,5,6,7,8,9 };
	int ans = InsertSearch(a, 4);
	cout << ans << endl;
	getchar();
	return 0;

}