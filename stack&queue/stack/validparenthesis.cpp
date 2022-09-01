#include<bits/stdc++.h>
using namespace std;

int longestvalid(string s)
{
    stack<int>st;
    st.push(-1);
    int max=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(') st.push(i);
        else{
            st.pop();
            if(st.empty()) st.push(i);
            else {
                int len=i-st.top();
                if(max<len) max=len;
            }
        }
    }
}
//another solution O(1)
int validlonget(string s)
{
   
    int maxi=0;
    int open=0;
    int close=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(') open++;
        else close++;
        if(open==close) maxi=max(maxi,open+close);
        else if(close>open)
        {
            open=close=0;
        }
}
}
