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

int diameterofTree(TreeNode* root,int & maxi)
{
    if(root==NULL) return 0;
    int lh=diameterofTree(root->left,maxi);
    int rh=diameterofTree(root->right,maxi);
    maxi=max(maxi,lh+rh);
    return 1 +max(lh,rh);
}