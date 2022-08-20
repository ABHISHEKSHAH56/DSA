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

TreeNode * buildbro(vector<int>&in,vector<int>& pre, int prestart,int preend,int instart,int inend ,unordered_map<int,int> & mp)
{
    if(prestart>preend || instart>inend) return NULL;
    TreeNode *root=new TreeNode(pre[prestart]);
    int inRoot=mp[root->val];
    int numsleft=inRoot-instart;
    root->left=buildbro(in,pre,prestart+1,prestart+numsleft,instart,inRoot-1,mp);
    root->right=buildbro(in,pre,prestart+numsleft+1,preend,inRoot+1,inend,mp);
    return root;
}


TreeNode * buildtree(vector<int>inorder,vector<int>postorder)
{
    //as concept we know that 
    //pre and post will give the idea who is root and inorder help to segrate the left and right part '
    //for that we need indexing 
    unordered_map<int,int>mp;
    for(int i=0; i<inorder.size(); i++) mp[inorder[i]]=i;
}