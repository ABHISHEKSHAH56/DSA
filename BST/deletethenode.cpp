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

//*************delete the node ****************
/**
 * @brief 
 * Zero-chid---then simmple 
 * one-child-simple delete and update the node 
 * two-child --find inorder succesor if right sub tree present else preorder successer
 * ------------how algo---
 * find inorder suceessor then swap the value and call again 
 */
TreeNode * deleteNode(TreeNode * root,int key)
{
    if(!root) return root;
    if(root->val>key) 
        root->left=deleteNode(root->left,key);
    else if(key>root->val)
        root->right=deleteNode(root->right,key); 
    else{
        //for zero one case
        if(!root->left) return root->right;
        else if (!root->right) return root->left;
        //for 2 child
        root->val=minvalue(root->right);
        root->right=deleteNode(root->right,root->val);
    }
    return root;
}

int minvalue(TreeNode *root)
{
    int min=root->val;
    while(root->left!=NULL)
    {
        min=root->left->val;
        root=root->left;
    }
    return min;
}