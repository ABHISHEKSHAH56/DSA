//every thing on right must be greater than root
//everything on left must be smaller from root 

//so mainting this above criteria we need two flag so that we keep in mind valu must be lie between this rant 
// be lie 
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

bool validateTree(TreeNode * root ,int mini,int maxi)
{
    if(!root) return true;    
    if( root->val>=maxi || root->val<=mini ) return false;
    return validateTree(root->left,mini,root->val) && validateTree(root->right ,root->val ,maxi);
}