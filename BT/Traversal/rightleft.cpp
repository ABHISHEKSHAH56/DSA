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

//itrative bhi kar sakte hai mgr space complexity jada hogi beacuse we have to store all vall in vectofr
//recursive 
//preorder nlr
//revserese preorder 

void rightside(TreeNode* root,int level,vector<int>res)
{
    if(root==NULL)return ;
    if(res.size()==level) res.push_back(root->val);
    rightside(root->right,level+1,res);
    rightside(root->left,level+1,res);
}