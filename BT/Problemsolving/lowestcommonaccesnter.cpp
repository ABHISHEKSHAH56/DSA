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

TreeNode * lca (TreeNode * root,int n1,int n2)
{
    if(root==NULL || root->val==n1|| root->val==n2) return root;
    TreeNode * l= lca( root->left ,n1 , n2 );
    TreeNode * r= lca( root->right ,n1 , n2 );
    if(l==NULL) return r;
    else if(r==NULL) return l;
    else return root;

}