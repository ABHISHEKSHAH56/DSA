#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    // write your code here
    if(str.size()==0)
    {
        cout<<asf<<endl;
        return ;
    }
    
    for(int i=0; i<str.size(); i++){
        char c=str[i];
        //cout<<str.substr(0,i)+str.substr(i+1)<<endl;
       printPermutations(str.substr(0,i)+str.substr(i+1),asf+c);
    }

}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}