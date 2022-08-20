#include <bits/stdc++.h>
using namespace std;

/**
 * @brief What's subsequence of abc --2^n
 * ["",a,b,c,bc,ac,ab,abc]
 * ? sub string  (N+1)*N/2 
 * [a,ab,abc,b,bc,c]
 * 
 */

//first method faith +expectations
//we dont need to store 
void printss(string s,string asf)
{
    if(s.size()==0)
    {
        cout<<asf<<endl;
        return ;
    }
    char c=s[0];
    printss(s.substr(1),asf);
    printss(s.substr(1),asf+c);
}

vector<string> gss(string s){
    // write your code here
    if(s.size()==0)
    {
        vector<string>ans={""};
        return ans;
    }
    char x=s[0];
    vector<string>ans=gss(s.substr(1));
    vector<string>out(ans);
    for(int i=0; i<ans.size(); i++)
    {
        out.push_back(x+out[i]);
    }
    return out;
    
    
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}
