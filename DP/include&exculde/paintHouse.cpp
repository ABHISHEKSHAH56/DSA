//Binary Strings with no consecutive 0's 
#include<bits/stdc++.h>
using namespace std;
int painthouse1(vector<vector<int>>arr,int n)
{
    int r=arr[0][0];
    int b=arr[0][1];
    int g=arr[0][2];
    for(int i=1; i<arr.size(); i++)
    {
        int x=arr[i][0]+min(b,g);
        int y=arr[i][1]+min(r,g);
        int z=arr[i][2]+min(b,r);
        r=x;
        b=y;
        g=z;
    }
}
//paint house with many color 