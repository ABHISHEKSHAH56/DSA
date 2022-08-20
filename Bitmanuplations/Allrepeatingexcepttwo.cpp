#include <bits/stdc++.h>
using namespace std;


/**
 * @brief 
 * solutions is we have to make two set having the 
 * 
 */

void solve(vector<int>arr){
    int xxor=0;
    for(auto it:arr)
    {
        xxor^=it;
    }
    //rmb(right most bit )
    int rsb=xxor & -xxor;
    //now we make two set whose bits off and on 
    int x=0;
    int y=0;
    for(auto it:arr)
    {
        if((it & rsb) ==0)
        {
            x^=it;
        }
        else{
            y^=it;
        }
    }
    cout<<x<<" "<<y<<endl;
}

int main(){
   int n;
   cin>>n;
   vector<int>arr(n);
   for(int i=0; i<n; i++)
   {
        cin>>arr[i];
   } 
   solve(arr);
}