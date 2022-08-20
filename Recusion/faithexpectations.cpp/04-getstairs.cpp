#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * @brief Get the stair paths object
 * 1. You are given a number n representing number of stairs in a staircase.
   You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.
 
  f+E
 */

vector<string> get_stair_paths(int n) {
  //Write your code here
  if(n==0)
  {
      vector<string>ans={""};
      return ans;
  }
  if(n<0) { 
      vector<string> ans ;
      return ans ;
  }
  vector<string> step1=get_stair_paths(n-1);
  vector<string> step2=get_stair_paths( n-2);
  vector<string> step3=get_stair_paths( n-3);
  vector<string> ans;
  for(int i=0; i<step1.size();i++){
    ans.push_back('1'+step1[i]);
  }
   for(int i=0; i<step2.size();i++){
    ans.push_back('2'+step2[i]);
  }
   for(int i=0; i<step3.size();i++){
    ans.push_back('3'+step3[i]);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<string> ans = get_stair_paths(n);
  int cnt = 0;

  cout << '[';
  for (string str : ans) {
    if (cnt != ans.size() - 1)
      cout << str << ", ";
    else
      cout << str;
    cnt++;
  }
  cout << ']';
}




