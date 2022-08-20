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
void markparent(TreeNode *root,unordered_map<TreeNode *,TreeNode *>& parentracker)
{
    queue<TreeNode *>q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode * current= q.front();
        q.pop();
        if(current->left)
        {
            parentracker[current->left]=current;
            q.push(current->left);
        }
        if(current->right)
        {
            parentracker[current->right]=current;
            q.push(current->right);
        }
    }
    
}
vector<int> distance(TreeNode* root,TreeNode * target ,int k)
{
    unordered_map<TreeNode *,TreeNode *> parentracker;
    markparent(root,parentracker);
    unordered_map<TreeNode* ,bool>visited;
    queue<TreeNode * >q;
    q.push(target);
    visited[target]=true;
    int curr_level=0;
    while(!q.empty())
    {
        int size=q.size();
        if(curr_level==k) break;
        for(int i=0; i<size; i++)
        {
            auto it=q.front();
            q.pop();
            if(it->left && !visited[it->left])
            {
                q.push(it->left);
               visited[it->left]=true;
            }
            if(it->right && !visited[it->right])
            {
                q.push(it->right);
                visited[it->right]=true;
            }
            if(parentracker[it] && !visited[parentracker[it]]){
                q.push(parentracker[it]);
                visited[parentracker[it]]=true;
            }
        }
        curr_level++;
    }
    vector<int>res;
    while(!q.empty())
    {
        auto it=q.front(); q.pop();
        res.push_back(it->val);
    }
    return res;

}