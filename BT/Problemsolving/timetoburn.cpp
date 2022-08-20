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

TreeNode* parentmaker(TreeNode *root,int start ,map<TreeNode *,TreeNode *>& parentTracker)
{
    queue<TreeNode *>q;
    q.push(root);
    TreeNode* res;
    while (!q.empty())
    {
        auto it=q.front(); q.pop();
        if(it->val==start) res=it;
        if(it->left)
        {
            q.push(it->left);
            parentTracker[it->left]=it;
        }
         if(it->right)
        {
            q.push(it->right);
            parentTracker[it->right]=it;
        }
        /* code */
    }
    return res;
    
}
int timetobrust(map<TreeNode *,TreeNode *> &parentTracker,TreeNode * target)
{
    queue<TreeNode *>q;
    q.push(target);
    int cur=0;
    unordered_map<TreeNode *,bool>visi;
    visi[target]=true;
    while(!q.empty())
    {
        int size=q.size();
        int flo=0;
        for(int i=0; i<size; i++)
        {
            auto it=q.front(); q.pop();
            if(it->left && !visi[it->left])
            {
                visi[it->left]=true;
                q.push(it->left);
                flo=1;
            } 
            if(it->right && !visi[it->right] ) q.push(it->right);
            if(parentTracker[it] && !visi[parentTracker[it]]) q.push(parentTracker[it]);
        }
        //i skip some part and below need to check is acutall
        if(flo) cur++;
    }
    return cur;
}

int timetoburn(TreeNode * root,int start)
{
    map<TreeNode *,TreeNode *>parentTracker;
    TreeNode *target=parentmaker(root,start,parentTracker);
    return timetobrust(parentTracker,target);
}