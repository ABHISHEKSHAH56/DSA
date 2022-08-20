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

//left excluding leaf node + leafnode + right excluding leaf ndode
bool isLeafNode(TreeNode*root)
{
    if(root->left ==NULL && root->right==NULL) return true;
    return false;
}


void  addLeftBoundary(TreeNode*root,vector<int>&ans)
{
    TreeNode* temp=root->left;
    while(temp)
    {
        if(!isLeafNode(temp)) ans.push_back(temp->val);
        if(temp->left!=NULL) temp=temp->left;
        else temp=temp->right;
    }

}

void  addRightBoundary(TreeNode*root,vector<int>&ans)
{
    TreeNode* temp=root->right;
    vector<int>res;
    while(temp)
    {
        if(!isLeafNode(temp)) res.push_back(temp->val);
        if(temp->right!=NULL) temp=temp->right;
        else temp=temp->left;
    }
    reverse(res.begin(),res.end());
    ans.insert(ans.end(),res.begin(),res.end());

}
void addLeafNodes(TreeNode*root,vector<int>&res)
{
    if(isLeafNode(root)) {
        res.push_back(root->val);
        return ;
    }
    if(root->left)addLeafNodes(root->left,res);
    if(root->right)addLeafNodes(root->right,res);
}

vector<int>boundary(TreeNode * root)
{
    vector<int>res;
    if(root==NULL) return res;
    if(!isLeafNode(root)) res.push_back(root->val);
    addLeftBoundary(root,res);
    addLeafNodes(root,res);
    addRightBoundary(root,res);
    return res;

}