
class Solution {
public:
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }
   
    void ordertraversal(TreeNode* root,vector<vector<int>>& ans,int levels){
       if(root==NULL) return;
       ans[levels].push_back(root->val);
       ordertraversal(root->left,ans,levels+1);
       ordertraversal(root->right,ans,levels+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = level(root);
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++){
            vector<int> v;
            ans.push_back(v);
        }
        ordertraversal(root,ans,0);
         return ans;
    }
};