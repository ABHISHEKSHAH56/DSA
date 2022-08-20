#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
    for (int i = 31; i >=0; i--)
    {
        int mask=1<<i;
        int rev=0;
        int j=0;
        bool flag =false;
        if(flag)
        {
            if((n & mask)==0) continue;
            else{
                rev|=1<<j;
            }
            j++;

        }else{
            if((n & mask)==0) continue;
            else{
                flag=true;
                rev|=1<<j;
                j++;
            }
        }
    }
    
}