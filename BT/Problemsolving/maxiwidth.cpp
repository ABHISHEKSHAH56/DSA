//maximum width means ---> no of nodes in a level between  any 2 nodes

//             1                           1
//         3         2                 3       2
//    5      3          4          5

//    this will have 4 width       this will have 2 


//             1
//         3       2
//     5               4
// 7                       6 ----> this will have 8
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

//overflow na ho jaaye --so we need to otimize the indexing

int maximumwidth(TreeNode* root)
{
    if(!root) return 0;
    int ans=0;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        int size=q.size();
        int min=q.front().second;
        int first,last;
        for(int i=0; i<size; i++)
        {
            int cur_id=q.front().second-min;
            auto it=q.front().first;
            q.pop();
            if(i==0) first=cur_id;
            if(i==size-1) last=cur_id;
            if(it->left) q.push({it->left,cur_id*2+1});
            if(it->right) q.push({it->right,cur_id*2+2});

        }
        ans=max(ans,last-first+1);
    }
    return ans ;

}