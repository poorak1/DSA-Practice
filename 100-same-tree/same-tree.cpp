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
    int helper(TreeNode* p, TreeNode* q){
        if(p==nullptr && q==nullptr) return 0;
        if(p==nullptr && q!= nullptr) return -1;
        if(p!=nullptr && q== nullptr) return -1;

        if(p->val != q->val) return -1;

        int l = helper(p->left, q->left);
        int r = helper(p->right, q->right);

        if(l== -1 || r== -1) return -1;

        return 0;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        int final = helper(p, q);

        if(final == -1) return false;
        return true;
    }
};