#include<iostream>
#include<vector>
using namespace std;

void ReplaceBlank(char *str, int length)
{
	if (str == nullptr || length <= 0)//前置条件
		return;
	int originallength = 0;//字符串原长
	int numberOfBlank = 0;//空格个数
	int i = 0;
	//遍历字符串
	while (str[i]!='\0')
	{
		originallength++;
		if (str[i] == ' ')
			numberOfBlank++;
		i++;
	}
	int newLength = originallength + numberOfBlank * 2;//替换后的字符串长度
	if (newLength > length)
		return;
	int indexOforiginal = originallength;
	int indexOfnew = newLength;
	while (indexOforiginal>=0&&indexOfnew>indexOforiginal)
	{
		if (str[indexOforiginal] == ' ')
		{
			str[indexOfnew--] = '0';
			str[indexOfnew--] = '2';
			str[indexOfnew--] = '%';
		}
		else
		{
			str[indexOfnew--] = str[indexOforiginal];
		}
		--indexOforiginal;
	}

}

int main()
{
	char str[] = " helloworld";
	ReplaceBlank(str, 100);
	cout << str << endl;
	return 0;
}
