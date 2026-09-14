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
    string dfscheck(TreeNode* root, vector<TreeNode*> &ans, unordered_map<string, int> &mapp){
        if(root == NULL) return "#";
        string s = "";

        s = to_string(root->val) + "," + dfscheck(root->left,ans,mapp) + dfscheck(root->right,ans,mapp);

        if(mapp[s] == 1){
            ans.push_back(root);
        }
        mapp[s]++;

        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string , int> mapp;
        dfscheck(root,ans, mapp);
        return ans;
    }
};