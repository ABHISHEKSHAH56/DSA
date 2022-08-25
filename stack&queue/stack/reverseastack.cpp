#include<bits/stdc++.h>
using namespace std;

void insertelement(stack<int>& st, int count)
{
    if(st.empty())
    {
        st.push(count);
        return ;
    }
    int x=st.top();
    st.pop();   
    insertelement(st,count);
    st.push(x);
}

void reversestack(stack<int>& st )
{
  if(st.size()) return ;
   
    int x=st.top();
    st.pop();
    reversestack(st);
    insertelement(st,x);


}

int main()
{
    int n;
    stack<int>st;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        st.push(x);
    }
   int count=0; 
    reversestack(st);
   
}