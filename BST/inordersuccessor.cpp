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

TreeNode * inorderSuccess(TreeNode * root,TreeNode *p)
{
    TreeNode *successor=NULL;
    while(root!=NULL)
    {
        if(p->val>=root->val) root=root->right;
        else{
            successor=root;
            root=root->left;
        }
    }
}
TreeNode * inorderpreSuccess(TreeNode * root,TreeNode *p)
{
    TreeNode *presuccessor=NULL;
    while(root!=NULL)
    {
        if(p->val<=root->val) root=root->left;
        else{
            presuccessor=root;
            root=root->right;
        }
    }
}