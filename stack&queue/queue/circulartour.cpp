/***
 * N=4
 * in=(4,6) ,(6,5),(7,3),(4,5) 
 * 
 * 
 * 
 * ***/
#include<bits/stdc++.h>
using namespace std;
int  circulartravel(vector<int>pe,vector<int>di)
{
    int start=0; 
    int bal=0;
    int def=0;
    for(int k=0; k<pe.size(); k++)
    {
        bal+=pe[k]-di[k];
        if(bal<0)
        { 
            def+=bal;
            start=k+1;
            bal=0;
        }
        


    }
    //let suppose mid se start karte toh hum circular tour kar letet 
    //mid se phele ke deffiecne thao vo humne store kar liya agr mid ke aage ka bal
    //mile >0 ho jaayga iska matlb vha start karte toh traverse ho jaayga
    
    if(def+bal>=0) return start ;
    else return -1;
}