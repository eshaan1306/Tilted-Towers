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

    pair<int,int> soln(TreeNode* root){
        if (!root){
            return {0,0};
        }
        auto left = soln(root->left);
        auto right = soln(root->right);
        int cntLeft = left.first;
        int valLeft = left.second;
        int cntRight = right.first;
        int valRight = right.second;
        int totalCnt = cntLeft + cntRight + 1;
        int totalVal = valLeft + valRight + root->val;
        int avg = totalVal/totalCnt;
        if (avg == root->val){
            ans++;
        }
        return {totalCnt,totalVal};
    }

    int averageOfSubtree(TreeNode* root) {
        auto temp = soln(root);
        return ans;
    }
};/**
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

    pair<int,int> soln(TreeNode* root){
        if (!root){
            return {0,0};
        }
        auto left = soln(root->left);
        auto right = soln(root->right);
        int cntLeft = left.first;
        int valLeft = left.second;
        int cntRight = right.first;
        int valRight = right.second;
        int totalCnt = cntLeft + cntRight + 1;
        int totalVal = valLeft + valRight + root->val;
        int avg = totalVal/totalCnt;
        if (avg == root->val){
            ans++;
        }
        return {totalCnt,totalVal};
    }

    int averageOfSubtree(TreeNode* root) {
        auto temp = soln(root);
        return ans;
    }
};
