//check if there exist a pair with sum K

//we are given k any pair exist whose sum equal to k

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

/*
* 1 case is store the inorder and its problem reducr two sum proble ..use two pointer 
 ASC(N)+ vector spcae (N);
*/
//BST itertor
class BSTIterator{
    private: stack<TreeNode*>mystack;
            bool reverse=true;
    public:
        BSTIterator(TreeNode * root,bool reverse)
        {
            this->reverse=reverse;
            pushALL(root);
        }
        bool hasNext()
        {
            return !mystack.empty();
        }
        int next()
        {
            auto it=mystack.top();
            mystack.pop();
            if(reverse) pushALL(it->left);
            else pushALL(it->right);
            return it->val;
        }
        void pushALL(TreeNode* root)
        {
            for(; root!=NULL;){
                mystack.push(root);
                if(reverse) root=root->right;
                else root=root->left;
            }
        }
};
//as of now what i make hasnext will provide the same has having sorted vector

//only geting kind of ASC(N) overall is sc (1);
bool TwoSum(TreeNode* root,int k)
{
    if (!root) return false;
    BSTIterator l(root,false);
    BSTIterator r(root,true);
    int i=l.next();
    int j=r.next();
    while(i<j)
    {
        if(i+j==k) return true;
        else if(i+j<k) i=l.next();
        else j=r.next();
    }
    return false;

}