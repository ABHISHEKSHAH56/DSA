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

//we need to backtrack !!

TreeNode *temp=NULL;
TreeNode * kthaccenster(TreeNode * root ,int node,int &k)
{
    if(!root) return root;
    if(root->val==node || (temp=kthaccenster(root->left,node,k))||(temp=kthaccenster(root->right,node,k)))
    { 
            if(k==0){
            cout<<root->val<<endl;
            return NULL;
        }
        k--;
        return root;


    }
    return NULL;
}