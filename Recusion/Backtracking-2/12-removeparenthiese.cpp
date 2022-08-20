#include<bits/stdc++.h>
using namespace std;
int  getmin(string s){
    stack<char>st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(')
        {
            st.push('(');
        }
        else {
            if(st.empty()){
                st.push(')');
            }
            else if(st.top()=='(') st.pop();
            else  st.push(')');

        }
    }
    return st.size();
}
void solve(string s, int mr)
{
    if(mr==0)
    {
        if(getmin(s)==0)
        {
            cout<<s<<endl;
        }
        return ;
    }

    for(int i=0; i<s.size(); i++){
        string left=s.substr(0,i);
        string right=s.substr(i+1);
        solve(left+right,mr-1);
    }
}
int main()
{
    string valid;
    cin>>valid;
    int m=getmin(valid);
    solve(valid,m);
}