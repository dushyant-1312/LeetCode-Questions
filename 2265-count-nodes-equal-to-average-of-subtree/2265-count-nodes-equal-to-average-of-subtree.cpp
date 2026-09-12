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
    int ans  = 0; int nans = 0;
public:
    void dfscheck(TreeNode* root, int &sum , int &count){
        if(root == NULL) return;
        count++;
        sum += root->val;
        dfscheck(root->left, sum, count);
        dfscheck(root->right, sum, count);
    }

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if (sum / count == root->val)
            nans++;

        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL) return 0;

        // int count = 0; int sum = 0;
        // dfscheck(root, sum, count);

        // int check = sum/count;

        // if(check == root->val) ans++;

        // averageOfSubtree(root->left);
        // averageOfSubtree(root->right);

        // return ans;
        dfs(root);
        return nans;
    }
};