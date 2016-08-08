/******************************************************************************************
 * Data Structures in C++
 * 循环链表-约瑟夫环问题
 ******************************************************************************************/
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *link;
}LNode,*LinkList;

void JOSEPHUS(int n,int k,int m)
{
    LinkList p,r,list,curr;
    /*建立循环链表*/
    p=(LinkList)malloc(sizeof(LNode));
    p->data=0;
    p->link=p;
    curr=p;
    for(int i=1;i<n;i++)
    {
        LinkList t=(LinkList)malloc(sizeof(LNode));
        t->data=i;
        t->link=curr->link;
        curr->link=t;
        curr=t;
    }
    r=curr;
    while(k--)//将当前指针移动第一个报数的人
        r=p,p=p->link;
    while(n--)
    {
        for(int s=m-1;s--;r=p,p=p->link);
        r->link=p->link;
        printf("%d->",p->data);
        free(p);
        p=r->link;
    }
}
int main()
{
    JOSEPHUS(13,4,1);
    return 0;
}
