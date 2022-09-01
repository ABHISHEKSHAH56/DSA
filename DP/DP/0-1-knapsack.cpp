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
int knapSack(int w, vector<int> &wt, vector<int>&val, int n){
    cout<<" ----------------";

    vector<vector<int>>dp(n+1,vector<int>(w+1));
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<dp[0].size(); j++)
        {
            if(j==0 || i==0) dp[i][j]=0;
            else{
                if(j>=wt[i-1])
                {
                    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
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
    cout<<" ----------------";
    queue<Pairqeue*>q;
    q.push(new Pairqeue(n,w,""));
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        if(it->i==0 || it->j==0) cout<<it->psf<<endl;
        int  exec=dp[it->i-1][it->j];
        int incu=dp[it->i-1][it->j-wt[it->i-1]]+val[it->i-1];
        if(exec==dp[it->i][it->j]) q.push(new Pairqeue(it->i-1,it->j,it->psf));
        if(incu==dp[it->i][it->j]) q.push(new Pairqeue(it->i-1,it->j-wt[it->i-1],it->psf+to_string(wt[it->i-1])+"-"));
    }

    return dp[n][w] ;

}


int main() {
  int n;
  cin >> n;
  int w;
  cin>>w;

  vector<int> arr(n);
  vector<int>val(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  
  cout<<"----------";
  cout<<knapSack(w, arr, val,n);

}