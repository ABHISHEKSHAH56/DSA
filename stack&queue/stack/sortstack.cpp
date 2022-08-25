#include<bits/stdc++.h>
using namespace std;

void placeelement(stack<int>& st, int count)
{
    
    //we will find the exact post 
    if((!st.empty() && st.top()<count) || st.empty()){
        st.push(count);
        return ;

    } 
    int x=st.top();
    st.pop();
    placeelement(st,count);
    st.push(x);
    

}

void sortstack(stack<int>& st )
{
  if(st.size()) return ;
   
    int x=st.top();
    st.pop();
    sortstack(st);
    placeelement(st,x);


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
    sortstack(st);
   
}