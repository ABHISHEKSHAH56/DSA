#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
vector<bool> isPrime(N,1);
void sieve(int n )
{
    isPrime[0]=isPrime[1]=false;
    for(int i=2; i<N; i++)
    {
        if(isPrime[i])
        {
            for(int j=2*i; j<n; j+=i) isPrime[j]=false;
        }
    }
}