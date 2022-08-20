#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 * 
 */
//1. 2 for loop 


 //2.  two pinter approch 
static bool comp(pair<int,int>a,pair<int,int>b){
        if(a.first>b.first) return false ;
        return true;
    
}
vector<int> twoSum(vector<int>& num, int target) {
        vector<int>ans;
        vector<pair<int,int>>sol;
        
        
        for(int i=0; i<num.size(); i++)
        {
            sol.push_back({num[i],i});
        }
        sort(sol.begin(),sol.end(),comp);
        int l=0;
        int r=num.size()-1;
        while(l<r)
        {
            if(sol[l].first+ sol[r].first==target){
                ans.push_back(sol[l].second);
                ans.push_back(sol[r].second);
                break;
            }
            else if(sol[l].first+ sol[r].first>target)
                {
                    r--;
                }
                    else{
                        l++;
                    }
        }
        
        return ans;
        
    }

//3. hashing 

vector<int> twoSum(vector<int>& nums, int target) {

    vector<int> res;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); ++i) {

   	 if (mp.find(target - nums[i]) != mp.end()) {

   		 res.emplace_back(i);
   		 res.emplace_back(mp[target - nums[i]]);
   		 return res;
   	 }

   	 mp[nums[i]] = i;
    }

    return res;
}