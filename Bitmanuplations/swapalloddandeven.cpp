#include <bits/stdc++.h>
using namespace std;


/**
 * @brief 
 * solutions is we have to make two set having the 
 * 
 */

void solve(int n){

    int bo=0x55555555;
    int be=0xAAAAAAAA;

    int odds= (n& bo);
    int even=(n& be);
    odds<<1;
    even>>1;
    int c=(odds | even);
    cout<<c<<endl;

    
}

int main(){
   int n;
   
   solve(n);
}