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
    int dfscheck(TreeNode* root, int &count){
        if(root == NULL) return 0;
        // if(root->left == NULL && root->right == NULL){
        //     count++;
        // }
        // else{
            // if( (root->left == NULL || root->val >= root->left->val) && ( root->right == NULL || root->val >= root->right->val )){
            //    count++;
            // }
        // }
        int leftc = dfscheck(root->left, count);
        int rightc = dfscheck(root->right, count);
        int newmax = max(root->val , max(leftc, rightc));
        if(root->val == newmax) count++;
        return newmax;
           
    }
    int countDominantNodes(TreeNode* root) {
        int count = 0;
        if(root == NULL) return count;
        dfscheck(root, count);
        return count;
    }
};