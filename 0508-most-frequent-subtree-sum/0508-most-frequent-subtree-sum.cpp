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
    int dfscheck(TreeNode* root, unordered_map<int,int> &mapp){
        int total = 0;
        if(root == NULL) return total;

        // if(root->left != NULL && root->right != NULL) mapp[root->val + root->left->val + root->right->val]++;    // just of there left and right
        // else if(root->left != NULL && root->right == NULL) mapp[root->val + root->left->val]++;
        // else if(root->right != NULL && root->left == NULL)  mapp[root->val + root->right->val]++;
        // else mapp[root->val]++;

        total = root->val + dfscheck(root->left, mapp) + dfscheck(root->right, mapp);
        mapp[total]++;

        return total;

    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mapp;
        int maxi = INT_MIN;
        dfscheck(root, mapp);
        for(auto it : mapp){
            maxi = max(maxi, it.second);
        }
        vector<int> ans;
        for(auto it : mapp){
            if(it.second == maxi) ans.push_back(it.first);
        }
        return ans;
    }
};