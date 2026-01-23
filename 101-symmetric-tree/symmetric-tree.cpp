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
    string helper(TreeNode* r, string region){
        if(r == nullptr) return " ";

        string left = helper(r->left, "left");
        string right = helper(r->right, "right");

        if(region == "left") return to_string(r->val) + left + right;
        else return to_string(r->val) + right + left; 
 
    }
    bool isSymmetric(TreeNode* root) {
        
        string left = helper(root->left, "left");
        string right = helper(root->right, "right");

        cout<<left<<" "<<right;
        return left==right;
    }
};