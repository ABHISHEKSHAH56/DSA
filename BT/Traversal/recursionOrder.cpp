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

void preorder(TreeNode* root)
{
    if(root==NULL) return ;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

//post 
void postorder(TreeNode* root)
{
    if(root==NULL) return ;    
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
//inorder

void Inorder(TreeNode* root)
{
    if(root==NULL) return ;    
    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
    
}
