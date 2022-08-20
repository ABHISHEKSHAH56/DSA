#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * n ke me kar dunga n-1 ka recursion karke dega 
 */

int factorial(int n)
{
    // write your code here
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout <<factorial(n)<<endl;
}
