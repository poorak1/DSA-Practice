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
    bool helper(TreeNode* r, long long ub, long long lb){
        if(r == nullptr) return true;
        if((r->val <= lb ) || (r->val >= ub)) return false;

        bool left = helper(r->left, r->val, lb);
        bool right = helper(r->right, ub, r->val);

        if(!left || !right) return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MAX, LLONG_MIN);
    }
};