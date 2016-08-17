/* ��һ���ַ������������ִ��������Ӵ�*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
pair<int, string> fun(const string &str)
{
	vector<string>substrs;
	int maxcount = 1, count = 1;
	string substr;
	int i, len = str.length();
	for (int i = 0; i < len;i++)
	{
		substrs.push_back(str.substr(i, len - i));
	}
	for (i = 0; i < len;i++)
	{
		for (int j = i + 1; j < len;j++)
		{
			count = 1;
			if (substrs[i].substr(0,j-i)==substrs[j].substr(0,j-i))
			{
				count++;
				for (int k = j + (j - i); k < len;k+=j-i)
				{
					if (substrs[i].substr(0, j - i) == substrs[k].substr(0, j - i))
						count++;
					else
						break;
				}
				if (count>maxcount)//�ҳ����ִ��������Ӵ�
				{
					maxcount = count;
					substr = substrs[i].substr(0, j - i);
				}
			}

		}

	}
	return make_pair(maxcount, substr);
}

int main()
{
	string str;
	pair<int, string>rs;
	while (cin>>str)
	{
		rs = fun(str);
		cout << rs.second << ":" << rs.first << '\n';
	}
	return 0;
}
