/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int findFloor(Node* root, int x) {
        // code here
        int flooor = -1;
        while (root != nullptr) {
            if (root->data == x) {
                return root->data; 
            }
            if (x > root->data) {
                flooor = root->data; 
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return flooor;
    }
};