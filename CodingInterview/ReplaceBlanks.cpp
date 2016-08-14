#include<iostream>
#include<vector>
using namespace std;

void ReplaceBlank(char *str, int length)
{
	if (str == nullptr || length <= 0)//ǰ������
		return;
	int originallength = 0;//�ַ���ԭ��
	int numberOfBlank = 0;//�ո����
	int i = 0;
	//�����ַ���
	while (str[i]!='\0')
	{
		originallength++;
		if (str[i] == ' ')
			numberOfBlank++;
		i++;
	}
	int newLength = originallength + numberOfBlank * 2;//�滻����ַ�������
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
