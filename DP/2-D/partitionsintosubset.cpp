#include <bits/stdc++.h>
using namespace std;
//maximum no of ways 
int ksubsetspartitions(int n,int k  )
{
    vector<vector<int>> dp(k+1,vector<int>(n+1));
    for(int t=1; t<=k ; t++)
    {
        for(int p=1; p<=n ; p++)
        {
            if(p<t) dp[t][p]=0;
            else if(t==p) dp[t][p]=1;
            else dp[t][p]=dp[t-1][p-1]+t*dp[t][p-1];
        }
    }
}
//dp[t-1][p-1]--> t-1 team p-1 one player me baat gyi so aa apni alag team bany 
//dp[t][p-1] -->sare team p-1 palyer me bat gyi so p ki majbouri hai vo t team me se kisi ek team me jaaye 