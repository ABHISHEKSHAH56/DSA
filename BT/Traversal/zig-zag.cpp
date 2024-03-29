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

vector<vector<int>> solve(TreeNode * root) 
{
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<TreeNode*>q;
    q.push(root);
    bool leftright=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>level(size);
        for(int i=0; i<size; i++){
            TreeNode *node=q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            int index= leftright ? i: (size-1-i);
            level[index]=node->val;
        }
        leftright=!leftright;
        ans.push_back(level);
    }
    return ans;

}
