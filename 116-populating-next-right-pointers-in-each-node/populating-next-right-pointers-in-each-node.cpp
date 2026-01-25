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
    void helper(Node* r, map<int, Node*> &mpp, int level){
        if(r==nullptr) return;

        if(mpp.find(level) == mpp.end()){
            mpp[level] = r;
            r->next=nullptr;
        }else{
            mpp[level]->next = r;
            mpp[level] = r;
            r->next = nullptr;
        }

        helper(r->left, mpp, level+1);
        helper(r->right, mpp, level+1);
    }

    Node* connect(Node* root) {
        map<int, Node*> mpp;

        helper(root, mpp, 0);

        return root;
    }
};