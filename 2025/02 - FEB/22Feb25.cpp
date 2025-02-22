//      https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/
class Solution {
public:
    int idx;
    int nxtDepth, nxtValue;
    void dfs(TreeNode *cur, int depth, string &traversal) {
        int n = traversal.size();
        nxtDepth = 0, nxtValue = 0;
        while (idx < n && traversal[idx] == '-') {
            idx += 1, nxtDepth += 1;
        }
        while (idx < n && traversal[idx] != '-') {
            nxtValue = nxtValue * 10 + traversal[idx] - '0';
            idx += 1;
        }
        if (nxtDepth != depth + 1) return;
        TreeNode *nxt = new TreeNode(nxtValue);
        cur -> left = nxt;
        dfs(nxt, depth + 1, traversal);
        if (nxtDepth == depth + 1) {
            TreeNode *nxt = new TreeNode(nxtValue);
            dfs(nxt, depth + 1, traversal);
            cur -> right = nxt;
        }
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        TreeNode *root = new TreeNode();
        idx = 0;
        dfs(root, -1, traversal);
        return root -> left;
    }
};
