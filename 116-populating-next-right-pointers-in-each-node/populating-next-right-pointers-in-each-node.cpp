/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void helper(Node* r, map<int, vector<Node*>> &mpp, int level){
        if(r==nullptr) return;

        if(mpp.find(level) == mpp.end()){
            mpp[level].push_back(r);
            r->next=nullptr;
        }else{
            int last_idx = mpp[level].size()-1;
            mpp[level][last_idx]->next = r;
            mpp[level].push_back(r);
            r->next = nullptr;
        }

        helper(r->left, mpp, level+1);
        helper(r->right, mpp, level+1);
    }

    Node* connect(Node* root) {
        map<int, vector<Node*>> mpp;

        helper(root, mpp, 0);

        return root;
    }
};