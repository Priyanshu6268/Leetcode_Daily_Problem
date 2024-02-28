//.     https://leetcode.com/problems/find-bottom-left-tree-value/description/

class Solution {
    queue<TreeNode*> q;
    int last =0;
public:
    int findBottomLeftValue(TreeNode* root) {
        q.push(root);
        while(!q.empty()){
            int count = q.size();
            for(int i=0;i<count;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(i==0) last = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return last;
    }
};
