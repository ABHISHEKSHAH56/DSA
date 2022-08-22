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
bool check(TreeNode * root,int level,int &leafnode)
{
    if (!root) return true;
    if(!root->left && !root->right)
    {
        if(leafnode==0) leafnode=level;
        return leafnode==level;
    }
    return check(root->left,level+1,leafnode) && check(root->right,level+1,leafnode); 
}

bool isallatsamelevel(TreeNode * root)
{   int leafnode=0,level=0;
    return check(root, level,leafnode);
}