#include "../../debug.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution
{
    int ans = INT_MIN;
    int tmp, left=0, right=0;
    unordered_map<TreeNode*, int> G;
public:
    void recur(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        else
        {
            recur(root->left);
            recur(root->right);

            if (root->left)
                left = G[root->left];
            if (root->right)
                right = G[root->right];

            // Select Left Sub Tree
            int pos1 = max(left, 0) + root->val;
            // Select Right Sub Tree
            int pos2 = max(right, 0) + root->val;
            G[root] = max(pos1, pos2);

            // Root is now defining the new path?
            int pos3 = left + right + root->val;
            int tt = max(G[root], pos3);

            ans = max(tt, ans);
            left = 0;
            right = 0;

        }
    }


    int maxPathSum(TreeNode* root)
    {
        recur(root);
        return ans;
    }
};
