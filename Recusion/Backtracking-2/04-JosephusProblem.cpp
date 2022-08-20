#include<bits/stdc++.h>
using namespace std ;

/**
 * @brief 
1. You are given two numbers N and K.
2. N represents the total number of soldiers standing in a circle having position marked from 0 to N-1.
3. A cruel king wants to execute them but in a different way.
4. He starts executing soldiers from 0th position and proceeds around the circle in clockwise direction.
5. In each step, k-1 soldiers are skipped and the k-th soldier is executed.
6. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed soldiers are removed), until only the last soldier remains, who is given freedom.
7. You have to find the position of that lucky soldier.

 * 
 * @param n 
 * @param k 
 * @return ** int 
 */


int solve(int n, int k){
    if(n==1) return 0;
    int x=solve(n-1,k);
    int y=(x+k)%n;
    return y ;
}


int main(){
    int n,k; 
    cin>>n>>k;
    cout<<solve(n,k)<<endl;
}