#include <bits/stdc++.h>
using namespace std;

void solve(int ci,int len,map<char,int>mp,char od,string s)
{
    if(ci>len){    
        string sy;
        sy.push_back(od);
        string ans=s;
        if(sy.size()>0)
        {
            ans+=sy;
        
        
        }
        reverse(s.begin(),s.end());
        ans+=s;
        cout<<ans<<endl;
        return;
    }
    for(auto it:mp)
    {
        if(it.second>0){
            char x=it.first;
            mp[it.first]--;
            solve(ci+1,len,mp,od,s+x);
            mp[it.first]++;
        }
    }
}

int main(){

    string s;
    cin>>s;
    map<char,int>mp;
    for(int i=0; i<s.size(); i++){
        mp[s[i]]++;
    }
    //phele check krenge agr odd frequncy vala ek se jada nikal egi tp pilandrome possible nhi hai 
    int odd=0;
    int len=0;
    char odds;
    for(auto it:mp)
    {
        if(it.second%2!=0)
        {
            odds=it.first;
            odd++;
        }
        
            mp[it.first]=it.second/2;
            len++;
        
    }
    solve(1,len,mp,odds,"");
}