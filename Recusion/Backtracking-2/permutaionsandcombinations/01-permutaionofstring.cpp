#include <bits/stdc++.h>
using namespace std;

void solve(int ci ,int ts, map<char,int>mp,string asf)
{
    if(ci>ts)
    {
        //print
        return 
    }
    
    for(auto it : mp)
    {
        if(it.second>0)
        {   mp[it.first]--;
            solve(ci+1,ts,mp,asf+it.first);
            mp[it.first]++;
        }
       
    }
}


int main()
{
    //for number box 
    string s;
    cin>>s;
    map<char,int>mp;
    for(int i=0; i<s.size(); i++)
    {
        mp[s[i]]++;
    }
    
    solve(1,s.size(),mp,"");
}