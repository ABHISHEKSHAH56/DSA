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

void  roottonode(TreeNode*root ,int val,vector<int>res)
{
    if(root==NULL)return ;
    if(root->val==val)return ;
    res.push_back(root->val);
    roottonode(root->left,val,res);
    roottonode(root->right,val,res);
    res.pop_back();

}