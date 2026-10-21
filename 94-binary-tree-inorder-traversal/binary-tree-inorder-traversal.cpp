
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> ans;
      if(root==NULL) return  {} ;
   vector<int> left=  inorderTraversal(root->left);
         ans.push_back(root->val);
   vector<int> right= inorderTraversal(root->right);
      ans.insert(ans.begin(),left.begin(),left.end());
      ans.insert(ans.end(),right.begin(),right.end());
       return ans; 
    }
};