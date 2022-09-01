#include<bits/stdc++.h>
using namespace std;

void revv(queue<int>& q)
{
    if(q.empty()) return ;
    int x=q.front();
    q.pop();
    revv(q);
    q.push(x);
}
queue<int> rev(queue<int> q)
{
    // add code here.
   //1. method stack 
   // 2 recusion 
   stack<int>st;
   while(!q.empty())
   {
    st.push(q.front());
    q.pop();
   }
   while(!st.empty())
   {
        q.push(st.top());
        st.pop();
   }
}