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

    struct Node {
        int mn, mx, sum;
        bool isBST;
    };

    Node helper(TreeNode* r, int &ans){
        if(r == nullptr) return {INT_MAX, INT_MIN, 0, true};

        auto l = helper(r->left, ans);
        auto rr = helper(r->right, ans);

        if(l.isBST && rr.isBST && r->val > l.mx && r->val < rr.mn){

            int currSum = l.sum + rr.sum + r->val;
            ans = max(ans, currSum);

            return {
                min(r->val, l.mn),
                max(r->val, rr.mx),
                currSum,
                true
            };
        }

        return {INT_MIN, INT_MAX, 0, false};
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};