/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        bool leftToRight = true;
        while (!q.empty()) {
            int level_size = q.size();
            vector<int> temp(level_size);
            for (int i = 0; i < level_size; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (leftToRight)
                    temp[i] = t->val;
                else
                    temp[level_size - 1 - i] = t->val;
                if (t->left != NULL)
                    q.push(t->left);
                if (t->right != NULL)
                    q.push(t->right);
            }
            res.push_back(temp);
            leftToRight = !leftToRight;
        }
        return res;
    }
};