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
    int helper(TreeNode* r, int &maxi){
        if(r==nullptr) return -1001;

        int left = helper(r->left, maxi);
        int right = helper(r->right, maxi);

        maxi = max(right, max(left, max(maxi, r->val+left+right)));

        return max(r->val + max(left, right), r->val);
    }
    int maxPathSum(TreeNode* root) {
        if((root->left == nullptr) && (root->right== nullptr)) return root->val;

        int maxi= -1001;
        int final = helper(root, maxi);
        maxi = max(maxi, final);
        return maxi;
    }
};