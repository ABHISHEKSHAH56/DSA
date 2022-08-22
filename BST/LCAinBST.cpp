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

//both them  lie right 
//both them left 
//lie in left also and right  then the root will lca 
//another is root is one node

//TC--O(H)
TreeNode * LCA(TreeNode * root,int n1,int n2)
{
    if(!root) return root;

    if(root->val>n1 && root->val >n2)  return LCA(root->left,n1,n2);
    else if (root->val<n1 && root->val <n2) return LCA(root->left,n1,n2);
    else{
        return root ;
    }


}