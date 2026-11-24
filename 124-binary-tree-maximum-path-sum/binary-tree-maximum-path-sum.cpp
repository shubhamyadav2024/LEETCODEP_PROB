
class Solution {
public:
    int maxi =INT_MIN;
int maxpath(TreeNode* root){
    if(root==NULL) return 0;
    int leftsum = max(0,maxpath(root->left));
    int rightsum = max(0,maxpath(root->right));
    maxi = max(maxi,leftsum + rightsum + root->val);
    return  root->val+ max(leftsum,rightsum);
}
    int maxPathSum(TreeNode* root) {
        maxpath(root);
    return maxi;
    }
};