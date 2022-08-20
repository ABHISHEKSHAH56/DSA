#include <bits/stdc++.h>
using namespace std;


int laregetpowerof(int n)
{
    int x=0;
    while((1<<x)<=n)
    {
        x++;
    }
    return x-1;
}
int solve(int n)
{
    if(n==0) return 0;
    int x=laregetpowerof(n);
    int ans=0;
    int bitsuptoraise= x*(1<<x-1) ;
    int msbfrom2rxton= n-(1<<x)+1;
    ans=bitsuptoraise+msbfrom2rxton+solve(n-(1<<x));
    return ans;
}