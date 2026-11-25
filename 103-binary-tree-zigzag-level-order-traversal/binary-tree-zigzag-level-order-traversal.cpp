
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> res;
       if(root==NULL) return res;
       queue<TreeNode*>q;
       q.push(root);
       bool lr = true;
       while(!q.empty()){
        int n = q.size();
        vector<int>row(n);
        for(int i =0;i<n;i++){
            TreeNode* node = q.front();
            q.pop();
            int idx = (lr) ? i : (n-1-i);
            row[idx]= node->val;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        lr = !lr;
        res.push_back(row);
       }
       return res;

    }
};