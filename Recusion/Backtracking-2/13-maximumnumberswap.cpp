#include<bits/stdc++.h>
using namespace std;



string mx="-1";
void solve(string s,int k)
{
    if(stoi(s)>stoi(mx)) mx=s; 
    
    if(k==0) return ;
    
    
    for(int i=0; i<s.size();i++)
    {
        for(int j=i+1; j<s.size(); j++)
        {
            if(s[i]<s[j])
            {
                swap(s[i],s[j]);
                solve(s,k-1);
                swap(s[j],s[i]);
            }
        }
    }
}


int main(){
    string s; 
    int k;
    cin>>s>>k;
    solve(s,k);
    cout<<mx<<endl;
}