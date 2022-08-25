#include<bits/stdc++.h>
using namespace std;
//buthforce next 

//peceh se start karte hai 
// -1 dalnge sable phle 

//for any node st.top() me use chota hi hai to use store kar lenge varna pop karte rhenge jabtak use chota nhi mil jata 
//or push kardnge 
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int>ans(n);
    st.push(-1);
    for(int i=arr.size()-1; i>=0; i--)
    {
        while(st.top()>=arr[i]) st.pop();
        ans[i]=st.top();
        st.push(arr[i]);
    }
    
    return ans;
}
int main()
{

}