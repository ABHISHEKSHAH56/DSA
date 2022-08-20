#include <bits/stdc++.h>
using namespace std;

/**
 * @brief calulate power(x,n);
 * ? x^n= x^n/2* x^n/2 if n==even
 * ? x^n =x.x^n/2 .x^n/2 if n==odd
 * 
 * 
 */


int power(int x,int n){
   // write your code here

   if(n==0) return 1;
   return x*power(x,n-1);

}

//result come out into o(logn)
int power (int x,int n)
{   
    if(n==0) return 1;
    int y =power(x,n/2);
    if(n%2==0)
    {
        return y*y;
    }
    else{
        return x*y*y;
 }
}


int main(){
    int n,x; cin>>x>>n;
    cout<<power(x,n);
}