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
int Hl(TreeNode * root){
    if(root==NULL) return 0;
    return 1+Hl(root->left);

}
int Hr(TreeNode * root){
    if(root==NULL) return 0;
    return 1+Hr(root->right);

}

//o(N^2)
bool isBlancedTree(TreeNode * root)
{
    if(root!=NULL) return true;
    int lh=Hl(root->left);
    int hr=Hr(root->right);
    if(abs(lh-hr)>1) return false ;

    if(!isBlancedTree(root->left)|| !isBlancedTree(root->right)) return false ;
    return true;

}

//efficent approch 
int isblancedtree(TreeNode*root)
{
    if(root==NULL) return 0;
    int lh=isblancedtree(root->left);
    int rh=isblancedtree(root->right);
    if(lh==-1 && rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);
}