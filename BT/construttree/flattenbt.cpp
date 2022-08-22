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

//we dont need to make a new link list we need 
//to rearrange the bt such that its become link list

//so we will traverse in RLN

class Solution {
  TreeNode * prev = NULL;
  public:
    void flatten(TreeNode * root) {
      if (root == NULL) return;

      flatten(root -> right);
      flatten(root -> left);

      root -> right = prev;
      root -> left = NULL;
      prev = root;
    }

};

class SatckSolution {
  TreeNode * prev = NULL;
  public:
   void flatten(TreeNode * root) {
  if (root == NULL) return;
  stack < TreeNode * > st;
  st.push(root);
  while (!st.empty()) {
    TreeNode * cur = st.top();
    st.pop();

    if (cur -> right != NULL) {
      st.push(cur -> right);
    }
    if (cur -> left != NULL) {
      st.push(cur -> left);
    }
    if (!st.empty()) {
      cur -> right = st.top();
    }
    cur -> left = NULL;
  }

}
};

///SC(1)
//nlr
//moris traversal

//left subtree right most element must be point to root right left 

class Solution1 {
  TreeNode * prev = NULL;
  public:
   void flatten(TreeNode* root) {
        TreeNode* cur = root;
		while (cur)
		{
			if(cur->left)
			{
				TreeNode* pre = cur->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
    }



};
