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
    void helper(TreeNode* r, int k, vector<int> &inorder, int &final){
        if((r ==  nullptr) || (final != -1)) return;
        helper(r->left, k, inorder, final);

        if (final == -1) {
            inorder.push_back(r->val);
            if (inorder.size() == k) {
                final = r->val;
                return;
            }
        }
        
        helper(r->right, k, inorder, final);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        int final = -1;
        helper(root, k, inorder, final);
        
        return final;
    }
};