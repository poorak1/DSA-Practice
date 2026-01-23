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
    TreeNode* helper(vector<int> postorder, int poststart, int postend, vector<int> inorder, int instart, int inend, map<int, int> &inmap){
        if(poststart > postend || instart > inend) return nullptr;

        TreeNode* root = new TreeNode(postorder[postend]);

        int inpos = inmap[postorder[postend]];
        int numsleft = inpos - instart;

        root->left = helper(postorder, poststart, poststart+numsleft-1, inorder, instart, instart+numsleft-1, inmap);
        root->right = helper(postorder, poststart+numsleft, postend-1, inorder, inpos+1, inend, inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inmap;

        for(int i=0; i<inorder.size(); i++){
            inmap[inorder[i]] = i;
        }

        TreeNode* root = helper(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inmap);

        return root;
    }
};