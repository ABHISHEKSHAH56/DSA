/*
* preorder--[8,5,1,7,10,12] NLR
*/
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

//bruth TC->O(N*N)

/*
* 1 Approch would be sort the preorder and we get the inorder 
TC --O(NlogN)+o(N)
SC---O(N); 
*/
//case 2 use upper bound 

TreeNode * build(vector<int> & A,int & i ,int bound)
{
    if(i==A.size() || A[i]>bound) return NULL;
    TreeNode * root=new TreeNode(A[i++]);
    root->left=build(A,i,root->val);
    root->right=build(A,i,bound);
    return root;
}
TreeNode * bstform(vector<int> &A)
{
    int i=0; 
    return build(A,i,INT_MAX);

}