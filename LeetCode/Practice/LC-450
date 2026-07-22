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

    //modifies the subtree rooted at the node that i have to delete
    TreeNode* helper(TreeNode* root){
    if (!root->left){
        return root->right;
    }
    else if (!root->right){
        return root->left;
    }
    TreeNode* par=root;
    TreeNode* cur=root->right;
    while(cur->left){
        par=cur;
        cur=cur->left;
    }
    if(par!=root){            
        par->left=cur->right;
        cur->right=root->right;
    }
    cur->left=root->left;
    root->left=nullptr;
    root->right=nullptr;
    return cur;
}

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root){
            return nullptr;
        }
        if (root->val==key){
            return helper(root);
        }
        else if (root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};