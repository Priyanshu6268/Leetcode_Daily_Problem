//    https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>ans; // to store the level sum
        queue<TreeNode*>q; // for level order traversal
        q.push(root);
        while(!q.empty()){
            long long size = q.size(),sum = 0;
            for(int i=0;i<size;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                sum += (long long)temp->val;
            }
            ans.push_back(sum);
        }
        sort(ans.begin(),ans.end()); // sorting the ans vector
        int n = ans.size();
        return (n >= k)?ans[n-k] : -1; // returning the result
    }
};