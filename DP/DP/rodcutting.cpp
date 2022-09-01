//rod cutting 
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Pairqeue{
    public:
    int i;
    int j;
    string psf;
    Pairqeue(int i ,int j,string psf)
    {
        this->i=i;
        this->j=j;
        this->psf=psf;
    }

};
int knapSack(vector<int>&val, int n){
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=val[0];
    for(int i=2; i<n+1; i++)
    {
        dp[i]=val[i-1];
        int li=1;
        int ri=i-1;
        while(li<=ri)
        {
            if(dp[i]<dp[li]+dp[ri]) dp[i]=dp[li]+dp[ri];
            li++;
            ri--;
        }
        
    }
    for(auto it:dp)
    {
        cout<<it<<" ";
    }
    return dp[n]; 

}


int main() {
  int n;
  cin >> n;
  
  vector<int>val(n);
  
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  
  cout<<"----------";
  cout<<knapSack(val,n);

}