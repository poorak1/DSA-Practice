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
    void helper(TreeNode* r, int depth, map<int, vector<int>> &mpp){
        if(r == nullptr) return;

        if((depth % 2)==0){ mpp[depth].push_back(r->val); }
        else{ mpp[depth].insert(mpp[depth].begin(), r->val); }

        helper(r->left, depth+1, mpp);
        helper(r->right, depth+1, mpp);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        map<int, vector<int>> mpp;
        vector<vector<int>> final;

        helper(root, 0, mpp);

        for(auto &it : mpp){
            vector<int> tmp;
            for (int i = 0; i < it.second.size(); i++) {
                tmp.push_back(it.second[i]); 
            }
            final.push_back(tmp);
        }

        return final;
    }
};