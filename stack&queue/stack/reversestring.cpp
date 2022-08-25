#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    //by swaping 
    //also can be done by string 
    stack<char>st;
    for(auto it:s){
        st.push(it);
    }
    string reverse="";
    while(!st.empty()) {
        reverse+=st.top();
        st.pop();

    }
    cout<<reverse<<endl;
}