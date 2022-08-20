#include<bits/stdc++.h>
using namespace std ; 

/**
 * container ..dyanmic in nature   
 * 
 * 
 */

void explainPair()
{
    //how to declare 
    vector<int> v;//---> this will create the empty conatiner {}
    v.push_back(2);
    v.emplace_back(3); //--> fast then push_back
    
    //how  to insert 
    vector<pair<int,int>>p;
    p.push_back({2,3});

    //how to declare the vector set with default value ;
    vector<int> p(5,100); //-->[100,100,100,100,100]
    //its auto set with 0
    vector<int>v(5); //[0,0,0,0,0];
    //how to copy 

    vector<int> v1(5,100);
    vector<int>v2(v1);

}

//iterators

//how to declare 

//datatype :: iterator it =v.begin() ---> this will give the memory address

void iterator ()

{
    vector<int> v1;
    vector<int>:: iterator it =v1.begin();
    //at now it have v[0] address 
    it++;
    //it have the addrss of v1[1]
    //just like pointer 
    //how to get value 
    cout<<*it<<endl;
    //[20,40,60,80]
    vector<int>:: iterator it=v1.end(); //it will point the last next address 
    vector<int>:: iterator it=v1.rend(); // it will point before the v1[0];
    // 
    cout<<v1.back()<<endl;



}

void deletefun()
{
    //how to delete 
    vector<int> v;
    //v.erase(addressof locations);
    v.erase(v.begin(),v.end()); //[start,end) address

}
//how to insert 

void insertfun()
{
    vector<int>v(2,100); //[100,100];
    v.insert(v.begin(),300); //[300,100,100];
    v.insert(v.begin()+1,2,101); //[300,101,101,100,100] 
    

    //main
    vector<int> mp(2,11); 
    v.insert(v.begin(), mp.begin(),mp.end()); //--[11,11,300,101,101,100,100]

    //functions

    //v.size()
    //v.pop_back();
    /**
     * v1={2,3}
     * v2={4,6}
     * v1.swap(v2); --> v1==>[4,6 ] v2=[2,3]
     * 
     */
    //v.empty();
    //v.clear()

}
