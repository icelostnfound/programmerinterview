#include <iostream>
using namespace  std;
//链表结点
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead==NULL||k==0)//保证代码的鲁棒性
	{
		return NULL;
	}
	ListNode *pAhead = pListHead;
	ListNode *pBehind = NULL;
	for (unsigned int i = 0; i < k - 1;i++)
	{
		if (pAhead->next != NULL)//保证代码的鲁棒性
			pAhead=pAhead->next;
		else
		{
			return NULL;
		}
	}
	pBehind = pListHead;
	while (pAhead->next!=NULL)
	{
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pBehind;
}
int main()
{

	system("pause");
	return 0;
}
