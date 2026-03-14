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

    pair<int,int> helper(TreeNode* r, int &sum, int &currSum){

        if(r == nullptr) return {INT_MAX, INT_MIN};

        int leftSum = 0, rightSum = 0;

        auto l = helper(r->left, sum, leftSum);
        auto rr = helper(r->right, sum, rightSum);

        if(r->val > l.second && r->val < rr.first){

            currSum = leftSum + rightSum + r->val;
            sum = max(sum, currSum);

            return {
                min(r->val, l.first),
                max(r->val, rr.second)
            };
        }

        currSum = 0;
        return {INT_MIN, INT_MAX};
    }

    int maxSumBST(TreeNode* root) {
        int sum = 0;
        int temp = 0;
        helper(root, sum, temp);
        return sum;
    }
};