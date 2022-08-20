#include<bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * 
 * @param s1 
 * @param pat 
 * @param mp 
 */
void solve(string s1,string pat,map<char,string>& mp)
{
    if(pat.length()==0)
    {
        if(s1.length()==0){
            //ans will print 
        }
        return ;
    }
    
    char c=pat[0];
    string s=pat.substr(1);
    if(mp.find(c)!=mp.end())
    {
        string val=mp[c];
        if(s1.length()>=val.length())
        {
            string left=s1.substr(0,val.length());
            if(left==val)
            {
                solve(s1.substr(val.length()),s,mp);
            }
        }

    }
    else{
        for(int i=0; i<s1.size(); i++){
            string left=s1.substr(0,i);
            string right=s1.substr(i+1);
            mp[c]=left;
            solve(right,s,mp);
            mp.erase(c);

        }
    }
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    map<char,string>mp;
    solve(s1,s2,mp);
}