/*希尔排序*/
#include<iostream>
using namespace std;
typedef int elem_t;
void shell_insert(elem_t R[], const int start, const int end,const int gap)
{
	elem_t tmp;
	int i, j;
	for (i = start + gap; i < end;i++)
	{
		tmp = R[i];
		for (j = i - gap; tmp < R[j] && j >= start; j -= gap) {//与各节点比较
			R[j + gap] = R[j];
		}
		R[j + gap] = tmp;
	}
}
void shell_sort(elem_t a[], const int start, const int end) {
	int gap = end - start;
	while (gap > 1) {
		gap = gap / 3 + 1;
		shell_insert(a, start, end, gap);
	}
}
int main()
{
	int a[] = { 20, 4, 44, 21, 42, 22, 55, 34, 29, 90 };
	shell_sort(a, 0, 9);
	return 0;
}
