class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = height(root->left);
        if (lh == -1) return -1;   // left subtree unbalanced

        int rh = height(root->right);
        if (rh == -1) return -1;  // right subtree unbalanced

        if (abs(lh - rh) > 1) return -1; // current node unbalanced

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
