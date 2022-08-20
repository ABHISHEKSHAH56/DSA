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
int maxipathsum(TreeNode* root,int maxi)
{
    if(root==NULL)return 0;
    int ls=maxipathsum(root->left,maxi);
    int rs=maxipathsum(root->right,maxi);
    maxi=max(maxi,ls+rs+root->val);
    return root->val+max(ls,rs);
}