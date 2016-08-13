#include<iostream>
using namespace std;
typedef int elem_t;
//划分算法
void bubble_sort(elem_t R[], const int start, const int end)
{
	int i, j;
	int temp;
	for (i = start; i < end;i++)
	for (j = start; j < end - i; j++)
	{
		if (R[j]>R[j + 1])//升序排列
		{
			temp = R[j];
			R[j] = R[j + 1];
			R[j + 1] = temp;
		}
	}
}
int main()
{
	int a[] = { 20, 4, 44, 21, 42, 22, 55, 34, 29, 90 };
	bubble_sort(a, 0, 9);
	return 0;
}
