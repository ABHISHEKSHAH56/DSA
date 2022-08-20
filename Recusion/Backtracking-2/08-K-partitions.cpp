#include<bits/stdc++.h>
using namespace std;

/**
 * @brief 
1. You are given two integers n and k, where n represents number of elements and k represents 
number of subsets.
2. You have to partition n elements in k subsets and print all such configurations.
 *? sol
 choice existing set or new set me 
 2 options 
        (n,k)---> ((n-1),k) to iski mazburi hai kisi ke saat beet jaaye  or (n-1,k-1) or n ek alg set me jaayga 

 */

void solve(int i,int n, int k,int cones, vector<vector<int>> ans)
{
    if(i>n)
    {
        if(cones==k)
        {
            for(auto it: ans)
            {
                cout<<"[";
                for(auto z:it)
                {
                    cout<<z<<", ";
                }
                cout<<"]"<<endl;
            }
        }
    }

    for(int j=0; j<k ; j++)
    {
        if(ans[j].size()>0)
        {
            ans[j].push_back(i);  
            solve(i+1,n,k,cones,ans);
            ans[j].pop_back();
        }
        else{
            ans[j].push_back(i);
            solve(i+1,n,k,cones+1,ans);
            ans[j].pop_back();
            break;


        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> ans(k,vector<int>(k));
    solve(1,n,k,0,ans);
}