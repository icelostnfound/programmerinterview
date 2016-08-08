/******************************************************************************************
 * Data Structures in C++
 * 单链表的建立/测长/打印
 ******************************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string>
#include<conio.h>
using namespace std;
typedef struct student{
    int data;
    struct student *next;
}node;
//建表
node *creat()
{
    node *head ,*p,*s;
    int x,cycle=1;
    head=(node*)malloc(sizeof(node));
    p=head;
    while(cycle)
    {
        cout<<"\n"<<"Please enter the data:";
        cin>>x;
        if(x)
        {
            s=(node*)malloc(sizeof(node));
            s->data=x;
            cout<<"\n"<<s->data;
            p->next=s;
            p=s;
        }
        else{
            cycle=0;
        }
    }
    head=head->next;
    p->next=nullptr;
    printf("\n yyy %d",head->data);
    return head;
}
//测长
int length(node *head)
{
    int n=0;
    node *p;
    p=head;
    while(p!=NULL)
    {
        p=p->next;
        n++;
    }
    return n;
}
//打印
void print(node *head)
{
    node *p;int n;
    n=length(head);
    p=head;
    if(head!=NULL)
        while(p!=NULL)
    {
        cout<<"\n"<<p->data;
        p=p->next;
    }
}
//删除
node* delete(node* head,int num)
{
    node *p1,*p2;
    p1=head;
    while(num!=p1->data&&p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
    }
    if(p1->data=num)
    {
        if(p1=head)
        {
            head=p1->next;
            free(p1);
        }
        else
        {
            p2->next=p1->next;
            free(p1);
        }
    }
    else
    {
         cout<<"\n"<<num<<" could not been found";
    }
    return head;
}
//插入
node* insert(node *head,int num)
{
     node *p0,*p1,p2;
     p1=head;
     p0=(node*)malloc(sizeof(node));
     p0->data=num;
     while(p0->data>p1->data&&p1->next!=NULL)
     {
         p2=p1;
         p1=p1->next;
     }
     if(p0->data<=p1->data)
     {
         if(head==p1)
         {
             p0->next=p1;
             head=p0;
         }
         else
         {
             p2->next=po;
             p0->next=p1;
         }
     }
     else{
        p1->next=p0;
        p0->NULL;
     }
     return head;
}
//排序
node sort(node* head)
{
    node *p,*p2,*p3;
    int n;
    int temp;
    n=length(head);
    if(head==NULL||head->next==NULL)
        return head;
    p=head;
    //冒泡排序
    for(int j=1;j<n;++j)
    {
        p=head;
        for(int i=0;i<n-j;++i)
        {
            if(p->data>p->next->data)
            {
                temp=p->data;
                p->data=next->data;
                next->data=temp;
            }
            p=p->next;
        }
    }
    return head;
}
//逆置
node *reverse(node* head)
{
    node *p1,*p2,*p3;
    if(head==NULL||head->next==NULL)
        return head;
    p1=head,p2=head->next;
    while(p2)
    {
        p3=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p3;
    }
    head->next=NULL;
    head=p1;
    return head;
}
int  main()
{
	node *lis;
	lis=creat();
	print(lis);
	return 0;
}

