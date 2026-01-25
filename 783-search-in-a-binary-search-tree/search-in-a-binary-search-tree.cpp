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
    void helper(TreeNode* r, TreeNode* &found, int val){
        if(r==nullptr) return;

        if(r->val == val){ 
            found = r; 
            return;
        }
        if(r->val < val) helper(r->right, found, val);
        else helper(r->left, found, val);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* found = nullptr;

        helper(root, found, val);

        return found;
    }
};