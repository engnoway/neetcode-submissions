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
int getdepth(TreeNode* root, int& diam) {
    if (root == nullptr) return 0;

    int leftdepth = getdepth(root->left,diam);
    int rightdepth = getdepth(root->right,diam);
    diam = max(diam, leftdepth + rightdepth);
    return 1+max(leftdepth,rightdepth);
}
class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getdepth(root, diameter);
        return diameter;
    }
};
