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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& D)
    {
        vector<TreeNode*> ans;
        unordered_map<TreeNode*, TreeNode*> parent;

        // Performing Post Order Traversal
        vector<TreeNode*> postOrder;
        vector<TreeNode*> St;
        St.push_back(root);
        while(!St.empty())
        {
            auto node = St.back();
            St.pop_back();
            if(node != nullptr)
            {
                postOrder.push_back(node);
            }
            if(node->left)
            {
                parent[node->left] = node;
                St.push_back(node->left);
            }
            if(node->right)
            {
                parent[node->right] = node;
                St.push_back(node->right);
            }
        }
        reverse(postOrder.begin(), postOrder.end());

        /*
             In the post-order, if the node is to be deleted, add their children as new root.
             Also update their parent pointers
        */

        vector<TreeNode*> root_deleted;
        for(auto c: postOrder)
        {
            if(find(D.begin(), D.end(), c->val) != D.end())
            {
                root_deleted.push_back(c);
                // Get the Parent node, and assign it null.
                if(parent[c] != nullptr  && parent[c]->left == c)
                {
                    parent[c]->left = nullptr;
                }
                if(parent[c] != nullptr && parent[c]->right == c)
                {
                    parent[c]->right = nullptr;
                }
                if(c->left)
                {
                    ans.push_back(c->left);
                }
                if(c->right)
                {
                    ans.push_back(c->right);
                }
            }
        }

        bool flag;
        flag = (find(root_deleted.begin(), root_deleted.end(), root) == root_deleted.end()) ? true : false;

        if(flag)
            ans.push_back(root);

        return ans;
    }
};
