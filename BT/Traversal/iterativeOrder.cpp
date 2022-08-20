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


//preorder
vector<int> Preorder(TreeNode* root )
{
    vector<int>ans;
    if(root==NULL) return ans;
    stack<TreeNode* >st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode * temp=st.top();
        st.pop();
        ans.push_back(temp->val);
        if(temp->right !=NULL) st.push(temp->right);
        if(temp->left !=NULL) st.push(temp->left);
    }
    return ans;

}

//inorder

vector<int> Preorder(TreeNode* root )
{
    vector<int>ans;
    stack<TreeNode* >st;
    TreeNode * node=root;
    while(true)
    {
       if(node!=NULL)
       {
        st.push(node);
        node=node->left;
       }
       else{
         if(st.empty()) break;
         node=st.top();
         st.pop();
         ans.push_back(node->val);
         node=node->right;

       }

    }
    return ans;

}
vector<int> Preorder(TreeNode* root )
{
    vector<int>ans;
    if(root==NULL) return ans;
    stack<TreeNode* >st,st2;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        st2.push(root);
        if(root->left!=NULL) st.push(root->left);
        if(root->right!=NULL)st.push(root->right);

    }
    while (!st2.empty())
    {
       ans.push_back(st2.top()->val);
       st2.pop();
    }
    
    return ans;

}