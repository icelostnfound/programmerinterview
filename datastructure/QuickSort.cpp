#include<iostream>
using namespace std;
typedef int elem_t;
//划分算法
int Paritition(elem_t R[],const int start,const int end)
{
	int i = start;
	int j = end;
	const elem_t pivot = R[i];
	while (i<j)
	{
		while (i < j&&R[j] >= pivot)j--;//从右向左扫描，查找第一个关键字小于pivot
		if (i < j)R[i++] = R[j];//找到之后交换，交换后指针i+1
		while (i < j&&R[i] <= pivot)i++;//从左向右扫描，查找第一个关键字大于pivot
		if (i < j)R[j--] = R[i];//找到之后交换，交换后指针j-1
	}
	R[i] = pivot;//基准记录已被最后定位
	return i;
}
//排序算法
void QuickSort(elem_t R[], const int start, const int end)
{
	int pivotpos;
	if (start<end)
	{
		pivotpos = Paritition(R, start, end);
		QuickSort(R, start, pivotpos - 1);
		QuickSort(R, pivotpos + 1, end);
	}
}
int main()
{
	int a[] = { 20, 4, 44, 21, 42, 22, 55, 34, 29, 90 };
	QuickSort(a, 0, 9);
	return 0;
}
