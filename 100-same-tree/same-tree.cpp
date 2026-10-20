
class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL && q !=NULL) return false;
        if(p!=NULL && q==NULL) return false;

        if(p->val != q->val) return false;
        int leftans= isSameTree(p->left,q->left);
        if(leftans == false ) return false;

        int rightans= isSameTree(p->right,q->right);
        if( rightans == false ) return false;
        return true;
    }
};