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
    void helper(TreeNode* r, TreeNode* &prev){
        if(r==nullptr) return;

        helper(r->right, prev);
        helper(r->left, prev);

        r->right = prev;
        r->left = nullptr;
        prev = r;
    }

    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        helper(root, prev);
    }
};