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

//         2                       45
//     35      10              35      10
// 2       3   5   2       30      5   8   2

// node=left+right;
// u can increase by 1 at many tmes 

void change(TreeNode* root)
{
    if(!root) return ;
    int child=0;
    if(root->left) child+=root->left->val;    
    if(root->right) child+=root->right->val;
    if(child>=root->val)  root->val=child;
    else{
        if(root->left) root->left->val=root->val;
        if(root->right) root->right->val=root->val;
    }
    change(root->left);
    change(root->right);
    int tot=0;
    if(root->left) tot +=root->left->val;
    if(root->right) tot+=root->right->val;
    if(root->left or root->right) root->val=tot;
}