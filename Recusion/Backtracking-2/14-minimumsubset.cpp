#include <bits/stdc++.h>
using namespace std;

int minsum=INT_MAX;
string ans="";
void solve(vector<int> arr,vector<int> s1,vector<int>s2,int idx,int ss1,int ss2){
    if(idx==arr.size()){
        if(minsum>abs(ss1-ss2) )
        {
            minsum=abs(ss1-ss2);
            
        }
        return ;
    }
    if(s1.size()<(arr.size()+1)/2)
    {
        s1.push_back(arr[idx]);
        solve(arr,s1,s2,idx+1,ss1+arr[idx],ss2);
        s1.pop_back();
    }
    if(s2.size()<(arr.size()+1)/2)
    {
        s2.push_back(arr[idx]);
        solve(arr,s1,s2,idx+1,ss1,ss2+arr[idx]);
        s2.pop_back();
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>ia(n);
    for(int i=0; i<n; i++)
    {
        cin>>ia[i];
    }
    vector<int>s1;
    vector<int>s2;
    
    solve(ia,s1,s2,0,0,0);
}