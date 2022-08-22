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

//there is always two nodes swap we have to find and swap so that its recover the BST 

// take the vector take the inorder check which can be swap 

//tc(n+nlogn)
//sc(N)

//two case possible 
// 1. swap node are adjacent 
// 2. swap node are not adjacent 

class recoverBST
{
private:
    /* data */
    TreeNode *prev;
    TreeNode *first;
    TreeNode *last;
    TreeNode *middle;

public:
    void inorder(TreeNode *root)
    {
        if(!root) return ;
        if(prev!=NULL && (root->val<prev->val))
        {
            //firts violations
            if(!first)
            {
                first=prev;
                middle=root;
            }
            else last=root;
        }
        prev=root;
        inorder(root->right);
    }
    void Recover(TreeNode* root)
    {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(last && first )
        {
            swap(first->val,last->val);
        }
        else if(first && middle) swap(first->val,last->val);
    }
    
};
