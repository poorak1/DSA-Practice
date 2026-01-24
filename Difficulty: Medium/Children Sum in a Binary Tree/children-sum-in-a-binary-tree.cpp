/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    int helper(Node* r){
        if(r==nullptr) return -1;
        
        int left_val = helper(r->left);
        int right_val = helper(r->right);
        
        if(left_val == -2 || right_val == -2) return -2;
        if(left_val == -1 && right_val == -1) return r->data;
        if(left_val == -1 && right_val != -1) left_val = 0;
        if(left_val != -1 && right_val == -1) right_val = 0;
        
        if(left_val + right_val != r->data) return -2;
        
        return r->data;
    }
  
    bool isSumProperty(Node *root) {
        // code here
        int final = helper(root);
        
        if(final == -2) return false;
        
        return true;
    }
};