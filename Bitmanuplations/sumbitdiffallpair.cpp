#include <bits/stdc++.h>
using namespace std;


/**
 * @brief 
 * solutions is we have to make two set having the 
 * 
 */

int  solve(vector<int>arr){
    int res=0; 
    for(int i=0; i<32; i++){
        long count =0; 
        for(auto it:arr){
            if((it & (1<<i))!=0) count++;
        }
        res+=(arr.size()-count) *count *2;
    }
    return res;
    
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