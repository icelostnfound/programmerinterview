#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <windows.h>
#include <algorithm>
using namespace std;
bool comp(const pair<vector<int>::iterator, int> a, const pair<vector<int>::iterator, int> b)
{
	return a.first < b.first;
}
void reOrderArray(vector<int> &array) {
	vector<int> arrayTemp;
	int count = 0;
	for (int i = 0; i < array.size(); i++)
	{
		if (array.at(i)&0x1!=0)
		{
			count++;
		}
		arrayTemp.push_back(array.at(i));
	}


	unsigned int length = array.size();
	vector<pair<vector<int>::iterator, int>> arraypair;
	if (array.empty() || length == 0)
	{
		return;
	}
	vector<int>::iterator pBegin = arrayTemp.begin();
	vector<int>::iterator pEnd = arrayTemp.end() - 1;

	while (pBegin < pEnd)
	{
		//����ƶ�pBeginֱ��ָ��ż��
		while (pBegin < pEnd && (*pBegin & 0x1) != 0)
		{
			pBegin++;
		}
		//��ǰ�ƶ�pEndֱ��ָ������
		while (pBegin < pEnd && (*pEnd & 0x1) == 0)
		{
			pEnd--;
		}
		//����
		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}

	}

	vector<int>::iterator Begin = array.begin();
	vector<int>::iterator End = array.end();
	for (int i = 0; i < length; i++)
	{
		vector<int>::iterator pFind = find(Begin, End, arrayTemp.at(i));
		arraypair.push_back(make_pair(pFind, arrayTemp.at(i)));
	}
	sort(arraypair.begin(), arraypair.begin()+count, comp);
	sort(arraypair.begin() + count, arraypair.end(), comp);
	array.clear();
	for (int j = 0; j < length;j++)
	{
		array.push_back(arraypair.at(j).second);
	}

}
int main()
{
	vector<int>sample = { 1, 2, 3, 4, 5,6,7 };
	reOrderArray(sample);
	return 0;
}
