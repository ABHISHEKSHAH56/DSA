// 1. You are given a string str.
// 2. You are required to calculate and print the count of subsequences of the nature a+b+c+.
// For abbc -> there are 3 subsequences. abc, abc, abbc
// For abcabc -> there are 7 subsequences. abc, abc, abbc, aabc, abcc, abc, abc.

// 2x+1
#include<bits/stdc++.h>
using namespace std;
int countaubsequence(string x)
{
    int a=0;
    int ab=0; 
    int abc =0;
    for(int i=0; i<x.size(); i++)
    {
        char st=x[i];
        if(st=='a') a=2*a+1;
        else if(st=='b') ab=2*ab+a;
        else if(st=='c') abc=2*abc+ab;
    }
    return abc;
}