#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> topview(TreeNode*root)
{
    vector<int>ans;
    if(root==NULL) return ans;
    map<int,int>mp;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        mp[it.second]=it.first->val;
        if(it.first->left) q.push({it.first->left,it.second-1});
        if(it.first->right) q.push({it.first->right,it.second+1});


    }
    for(auto it :mp){
        ans.push_back(it.second);

    }
    return ans;
}

