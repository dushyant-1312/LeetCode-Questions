/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void dfscheck(TreeNode* root, string &ans){
        if(root == NULL){
            // ans += "#,";
            return;
        }
        ans += to_string(root->val) + ',';
        dfscheck(root->left, ans);
        dfscheck(root->right, ans);
    }
    string serialize(TreeNode* root) {
        // if(root == NULL) return "";
        // string ans="";
        // dfscheck(root, ans);
        // return ans;
        if (!root) {
            return "";
        }
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == nullptr) {
                s.append("#,");
            } else {
                s.append(to_string(curr->val) + ',');

                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* build(int low, int high, vector<int> &nums) {
        if (low > high) return nullptr;
        int mid = (high + low)/2;
        if(nums[mid] == -1) return NULL;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(low, mid-1, nums);
        root->right = build(mid+1, high, nums);

        return root;
    }
    TreeNode* deserialize(string& data) {
        if (data.size() == 0) {
            return nullptr;
        }
        stringstream s(data);

        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#") {
                node->left = nullptr;
            } else {
                TreeNode* leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }

            getline(s, str, ',');
            if (str == "#") {
                node->right = nullptr;
            } else {
                TreeNode* rightnode = new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;