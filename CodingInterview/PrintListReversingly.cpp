#include<iostream>
#include<stack>
using namespace std;

typedef struct ListNode
{
	int m_nKey;
	ListNode *m_pNext;
};
void PrintListReversingly(ListNode* pHead)
{
	stack<ListNode*>nodes;
	ListNode* pNode = pHead;
	//��ÿ���ڵ�ѹ��ջ��
	while (pNode!=NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	//���
	while (!nodes.empty())
	{
		pNode = nodes.top();
		cout << pNode->m_nKey << '\t';
		nodes.pop();
	}
}
//�ݹ�
void PrintListReversingly_Recursively(ListNode* pHead)
{
	if (pHead!=NULL)
	{
		if (pHead->m_pNext!=NULL)
		{
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		cout << pNode->m_nKey << '\t';
	}

}