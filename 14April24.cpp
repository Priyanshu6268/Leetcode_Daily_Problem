//    https://leetcode.com/problems/sum-of-left-leaves/
class Solution {
public:
    void inorder(TreeNode* root,int & ans){
        if(!root)return;

        inorder(root->left,ans);
        if(root->left && !root->left->left && !root->left->right)ans+=root->left->val;
        inorder(root->right,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int ans=0;
        inorder(root,ans);
        return ans;
    }
};
