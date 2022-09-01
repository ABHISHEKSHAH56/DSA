//Binary Strings with no consecutive 0's 
#include<bits/stdc++.h>
using namespace std;
int countsummaxi(vector<int>arr,int n)
{
    int inc=arr[0];
    int exc=0;
    for(int i=1; i<n; i++)
    {
        int temp=exc+arr[i];
        int ptr=max(inc,exc);
        inc=temp;
        exc=ptr;
    }
    return max(inc,exc);
}