#include<iostream>
#include<vector>
using namespace std;

bool Find(vector<vector<int> > array, int target)
{
	bool found = false;
	int rows = array.size();
	int cloumns = array.at(0).size();

	//选取数组右上角的数字，等于查找的数字的话，查找结束，大于的话，剔除列，小于的话剔除行
	if (!array.empty() && rows > 0 && cloumns > 0)
	{
		int row = 0;
		int cloumn = cloumns - 1;
		while (row<rows&&cloumn>=0)
		{
			if (array[row][cloumn] == target)
			{
				found = true;
				break;
			}
			else if (array[row][cloumn] > target)
			{
				--cloumn;
			}
			else
			{
				++row;
			}
		}
	}
	return found;
}

int main()
{
	vector<vector<int> > array;
	vector<int>arr;
	int a[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr.push_back(a[i][j]);
		}
		array.push_back(arr);
		arr.clear();
	}
	cout << Find(array,1) << endl;
	return 0;
	}
