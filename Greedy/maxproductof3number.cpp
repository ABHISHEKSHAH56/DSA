#include <bits/stdc++.h>
using namespace std;
//--------maximum product of three numbr in a given arr---/
// a b c d.....x y z 
//max(a*b*z, x*y*z)

//minimum operations 
//majority of element 

int majorityofelement(vector<int>arr)
{
    int a=arr[0];
    int f=1;
    for(int i=1; i<arr.size(); i++)
    {
        if(a==arr[i]) f++;
        else{
            f--;
        }
        if(f==0)
        {
            a=arr[i];
            f=1;
        }
    }
    //a is potential candidate 
    //loop lagynge count dekhe agr mile toh thiek varna nhi hai 
}