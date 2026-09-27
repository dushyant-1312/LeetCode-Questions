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
    TreeNode* dfscheck(unordered_map<int,int>& mapp, vector<int> &pre, vector<int> &in, int &index, int s, int e){
        if(s > e) return NULL;

        int rootv = pre[index]; index++;
        TreeNode* root = new TreeNode(rootv);

        int newi = mapp[rootv];


        root->left = dfscheck(mapp, pre, in, index, s, newi-1);
        root->right = dfscheck(mapp, pre, in, index, newi+1, e);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mapp;
        for(int i=0; i<inorder.size(); i++){
            mapp[inorder[i]] = i;
        }
        int index = 0;
        return dfscheck(mapp, preorder, inorder, index, 0, preorder.size()-1);
    }
};