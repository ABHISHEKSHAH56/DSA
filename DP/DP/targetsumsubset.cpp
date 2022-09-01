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
void targetSumSubset(int n, vector<int> arr, int tar) {

    vector<vector<bool>>dp(n+1,vector<bool>(tar+1));
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<dp[0].size(); j++)
        {
            if(j==0) dp[i][j]=true;
            else if(i==0) dp[i][j]=false;
            else{
               
                if(j>=arr[i-1])
                {
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    queue<Pairqeue*>q;
    q.push(new Pairqeue(n,tar,""));
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        if(it->i==0 && it->j==0) cout<<it->psf<<endl;
        bool exec=dp[it->i-1][it->j];
        if(exec) q.push(new Pairqeue(it->i-1,it->j,it->psf));
        if(it->j>=arr[it->i-1]){
            bool incl=dp[it->i][it->j-arr[it->i-1]];
            if(incl){
                q.push(new Pairqeue(it->i-1,it->j-arr[it->i-1],it->psf+to_string(arr[it->i-1])+"-"));
            }
        
        }

    }

    return ;

}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  int tar;
  cin >> tar;
  
  targetSumSubset(n, arr, tar);

}