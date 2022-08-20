#include<bits/stdc++.h>
using namespace std ;

/**
 * @brief 
 *  1. You are given a number.
    2. You have to print all the numbers from 1 to n in lexicographical order.
 * 
 * @param num 
 * @param n 
 * @return ** void 
 */
void dfs(int num,int n)
{
    if(num>n) return ;
    cout<<num<<endl;
    for(int i =0 ; i<10; i++)
    {
        dfs(num*10+i,n);
    }
    
}

int main()
{
    int n; 
    cin>>n; 
    for(int i=1; i<=9; i++)
    {
        dfs(i,n);
    }
}