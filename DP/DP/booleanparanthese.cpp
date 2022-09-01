#include<bits/stdc++.h>
using namespace std;

int solve (string s1,string s2)
{
    vector<vector<int>>dpt(s1.size(),vector<int>(s1.size()));
    vector<vector<int>>dpf(s1.size(),vector<int>(s1.size()));
    for(int g=0; g<s1.size(); g++)
    {
        for(int i=0,j=g ; j<s1.size(); i++,j++)
        {
            if(g==0) {
                if(s1[i]=='T') {
                    dpt[i][j]=1;
                    dpf[i][j]=0;
                }
                else{
                    dpt[i][j]=1;
                    dpf[i][j]=0;

                }
            }
            else{
                for(int k=i ; k<j ; k++)
                {
                    int ltc=dpt[i][k];
                    int rtc=dpt[k+1][j];
                    int ltf=dpf[i][k];
                    int rtf=dpf[k+1][j];
                    char opr=s2[k];
                    if(opr=='&')
                    {
                        dpt[i][j]+=ltc*rtc;
                        dpf[i][j]+=ltc*rtf+ltf*rtf+rtc*ltf;

                    }
                    else if(opr=='|')
                    {
                        dpf[i][j]+=ltf*rtf;
                        dpt[i][j]+=ltc*rtf+ltc*rtc+rtc*ltf;

                    }else{
                        dpf[i][j]+=ltf*rtf+ltc*rtc;
                        dpt[i][j]+=ltc*rtf+rtc*ltf;

                    }
                }
            }
        }
    }
    return dpt[0][s1.size()-1];
}

int main()
{
     
}