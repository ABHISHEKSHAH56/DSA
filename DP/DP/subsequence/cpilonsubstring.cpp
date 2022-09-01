#include <bits/stdc++.h>
#include <vector>
using namespace std;
//longest pilandromic sub string bhi hai !!
int solve(string s1)
{ int count=0;
    int maxlongest=0;
    vector<vector<int>>dp(s1.length(),vector<int>(s1.length()));
    for(int g=0; g<s1.length(); g++)
    {
        for(int i=0, j=g; j<dp.size(); i++,j++)
        {
            if(g==0) dp[i][j]=true;
            else if(g==1) dp[i][j]= s1[i]==s1[j]? true:false;
            else{
                if(s1[i]==s1[j]) dp[i][j]=dp[i][j-1];
                else dp[i][j]=false;
            }
            if(dp[i][j]){
                count++;
                maxlongest=g+1;
            }
        }
    }
    for(auto it:dp)
    {
        for(auto x:it)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return count;
}
int main(){
    string s1;   
    cin>>s1;
    cout<<solve(s1)<<endl;
}