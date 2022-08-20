#include <bits/stdc++.h>
using namespace std;

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
    vector<string>sol=solve(n);
}