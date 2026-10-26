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
int getdepth(TreeNode* root){
            if(root==nullptr) return 0;

    int leftdepth=getdepth(root->left);
    int rightdepth=getdepth(root->right);
    if(leftdepth==-1 ||rightdepth==-1||abs(leftdepth-rightdepth)>1)return -1;
    return 1+max(leftdepth,rightdepth);

}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getdepth(root)!=-1;
    }
};
