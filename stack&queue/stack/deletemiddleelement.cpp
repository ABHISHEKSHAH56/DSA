#include<bits/stdc++.h>
using namespace std;

void deletemidelement(stack<int>& st, int count,int size)
{
    if(count==size/2)
    {
        st.pop();
        return ;
    }
    int x=st.top();
    st.pop();   
    deletemidelement(st,count+1,size);
    st.push(x);
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
    int count =0; 
    int size=st.size();
    deletemidelement(st,count,size);
   
}