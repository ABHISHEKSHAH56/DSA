#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>hi)
{
    //bulding have width 
    int n=hi.size();
    int left=0;
    int right=0;
    int maxleft=0;
    int rightmax=0;
    int res=0;
    while(left<=right)
    {

        if(hi[left]<=hi[right])
        {
            if(hi[left]>=maxleft) maxleft=hi[left];
            else{
                res+=maxleft-hi[left];
            }
            left++;
        }
    
        else{
            if(hi[right]>=rightmax) rightmax=hi[right];
            else res+=rightmax-hi[right];
            right--;
        }
    }
}