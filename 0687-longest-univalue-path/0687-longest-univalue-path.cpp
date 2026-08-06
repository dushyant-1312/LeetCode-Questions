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
private:
    int dfscheck(TreeNode* root, int &count, int parent) {
        if (root == NULL) return 0;
      
        int left = dfscheck(root->left, count, root->val);
        int right = dfscheck(root->right, count, root->val);

        count = max(count, left + right);
        if (root->val == parent) {
            return max(left, right) + 1;
        } else {
            return 0;
        }
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        int count = 0;
        dfscheck(root, count, root->val); 
        return count;
    }
};