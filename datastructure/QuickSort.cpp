#include<iostream>
using namespace std;
typedef int elem_t;
//�����㷨
int Paritition(elem_t R[],const int start,const int end)
{
	int i = start;
	int j = end;
	const elem_t pivot = R[i];
	while (i<j)
	{
		while (i < j&&R[j] >= pivot)j--;//��������ɨ�裬���ҵ�һ���ؼ���С��pivot
		if (i < j)R[i++] = R[j];//�ҵ�֮�󽻻���������ָ��i+1
		while (i < j&&R[i] <= pivot)i++;//��������ɨ�裬���ҵ�һ���ؼ��ִ���pivot
		if (i < j)R[j--] = R[i];//�ҵ�֮�󽻻���������ָ��j-1
	}
	R[i] = pivot;//��׼��¼�ѱ����λ
	return i;
}
//�����㷨
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
