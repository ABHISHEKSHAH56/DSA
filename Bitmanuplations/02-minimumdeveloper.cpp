#include <bits/stdc++.h>
using namespace std;

/**
 * @brief we have to find minimum number of devloper so that company have all skill 
 * we will make subsquence and mak the bit mask of each employe 
 * if the want to join then we take or with previous else previous procceed 
 * 
 * 
 */
vector<string>solve(int n){
    if(n==1)
    {
        vector<string>s;
        s.push_back("0");
        s.push_back("1");
        return s;
    }
    vector<string>sol=solve(n-1);
    vector<string>sx;
    for(int i=0; i<sol.size(); i++)
    {
        string sco=sol[i];
        sx.push_back("0"+sco);
    }
    for(int i=sol.size()-1; i>=0; i--)
    {
        string sco=sol[i];
        sx.push_back("1"+sco);
    }
    return sx;
}

int main(){
    int n;
    cin>>n;
    vector<string>sol(n);
    for(int i=0; i<n; i++)
    {
        cin>>sol[i];
    }
    
}