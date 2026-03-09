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
    void inorder_helper(TreeNode* r, vector<int> &inorder){
        if(r == nullptr) return;
        inorder_helper(r->left, inorder);
        inorder.push_back(r->val);
        inorder_helper(r->right, inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorder_helper(root, inorder);

        int ptr_start = 0;
        int ptr_end = inorder.size()-1;

        if(ptr_start == ptr_end) return false;
        while(ptr_end > ptr_start){
            int sum = inorder[ptr_start] + inorder[ptr_end];
            if(sum > k){
                ptr_end--;
            }else if(sum < k){
                ptr_start++;
            }else if(sum == k){
                return true;
            }
        }
        return false;
        
    }
};