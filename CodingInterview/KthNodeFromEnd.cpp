#include <iostream>
using namespace  std;
//������
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead==NULL||k==0)//��֤�����³����
	{
		return NULL;
	}
	ListNode *pAhead = pListHead;
	ListNode *pBehind = NULL;
	for (unsigned int i = 0; i < k - 1;i++)
	{
		if (pAhead->next != NULL)//��֤�����³����
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
