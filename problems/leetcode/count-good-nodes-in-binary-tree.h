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

class Solution {
public:
    int goodNodes(TreeNode* root)
    {
        int ans = 0;
        deque< pair<TreeNode*, int> > Q;
        auto p = make_pair(root, root->val);
        Q.push_back(p);

        while(!Q.empty())
        {
            auto [node, value] = Q.back();
            if(node->val >= value)
                ans += 1;

            Q.pop_back();

            if(node->left)
            {
                Q.push_back(make_pair(node->left, max(node->left->val, value)));
            }
            if(node->right)
            {
                Q.push_back(make_pair(node->right, max(node->right->val, value)));
            }
        }
        return ans;
    }
};
