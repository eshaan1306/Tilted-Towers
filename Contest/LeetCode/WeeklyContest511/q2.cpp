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

    int ans=0;

    int soln(TreeNode* root){
        if (!root){
            return INT_MIN;
        }
        int maxi=root->val;
        maxi=max(maxi,soln(root->left));
        maxi=max(maxi,soln(root->right));
        if (maxi==root->val){
            ans++;
        }
        return maxi;
    }
    
    int countDominantNodes(TreeNode* root) {
        int temp=soln(root);
        return ans;
    }
};
