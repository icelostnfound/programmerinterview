#include<iostream>
#include<stack>

using namespace std;
template<class T>
struct MyQueue
{
    void push(T &t)
    {
        s1.push(t);
    }
    T front()
    {
        if(s2.empty())
        {
            if(s1.size()==0)throw;
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    void pop()
    {
        if(s2.empty())
        {
            if(s1.size()==0)throw;
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
       if(!s2.empty())
         s2.pop();
    }
    stack<T>s1;
    stack<T>s2;
};

int main()
{
    MyQueue<int>mq;
    int i;
    for(i=0;i<10;i++)
        mq.push(i);
    for(i=0;i<10;i++)
    {
        cout<<mq.front()<<endl;
        mq.pop();
    }
    return 0;
}
