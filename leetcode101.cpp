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
   
    TreeNode* invert_tree(TreeNode *node){
        if(node == NULL)
            return node;
        
        TreeNode* temp = node->left;
        node->left = invert_tree(node->right);
        node->right = invert_tree(temp);
        
        return node;
    }
    bool is_same_tree(TreeNode* node1, TreeNode* node2){
        if(node1 == NULL && node2 == NULL)
            return true;
        if( (node1 == NULL && node2) || (node1 && node2==NULL) )
            return false;
        if(node1->val != node2->val)
            return false;
        
        return is_same_tree(node1->left,node2->left) && is_same_tree(node1->right,node2->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        root->left = invert_tree(root->left);
        
        return is_same_tree(root->left,root->right);
    }
};
