#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
   int li=0;
   int ri=s.size()-1;
   while (li<ri)
   {
     char l=s[li];
     char r=s[ri];
     if(l!=r)return false;
     l++;
     r--;
   }
   return true;
   

}
void solve(string s,string asf)
{
    if(s.size()==0){
        cout<<asf<<endl;
    }
    
    for(int i=0; i<s.size(); i++)
    {
        string prefix=s.substr(0,i+1);
        if(isPalindrome(prefix))
        {
            solve(s.substr(i+1),asf+"("+prefix+") ");
        }
    }
}