/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool is_leaf(Node* r){
        if((r->left == nullptr) && (r->right == nullptr)) return true;
        return false;
    }
    void add_left(Node* root, vector<int> &res){
        Node* cur = root->left;
        while(cur){
            if(!is_leaf(cur)) res.push_back(cur->data);
            if(cur->left) cur=cur->left;
            else cur = cur->right;
        }
    }
    
    void add_right(Node* root, vector<int> &res){
        Node* cur = root->right;
        vector<int> tmp;
        while(cur){
            if(!is_leaf(cur)) tmp.push_back(cur->data);
            if(cur->right) cur=cur->right;
            else cur = cur->left;
        }
        
        for(int i=tmp.size()-1; i>=0; i--){
            res.push_back(tmp[i]);
        }
    }
    
    void add_leaves(Node* root, vector<int> &res){
        if(is_leaf(root)){
            res.push_back(root->data);
            return;
        }
        
        if(root->left) add_leaves(root->left, res);
        if(root->right) add_leaves(root->right, res);
    }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(!root) return res;
        if(!is_leaf(root)) res.push_back(root->data);
        
        add_left(root, res);
        add_leaves(root, res);
        add_right(root, res);
        
        return res;
        
    }
};