

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; int k;
    cin>>n; 
    cin>>k;

   vector<int>pep(k,0);
   pep[0]=1;
   pep[1]=1;
   int sum=pep[0]+pep[1];
  
   for(int i=2; i<k; i++)
    {
            pep[i]=sum;
            sum+=pep[i];
    }
    int j=k;
    int i=0;
    while(j<n)
    {
        pep.push_back(sum);
        sum+=pep.back()-pep.front();
        pep.erase(pep.begin());
        j++;
    }
    cout<<" "<<sum;
    
}
