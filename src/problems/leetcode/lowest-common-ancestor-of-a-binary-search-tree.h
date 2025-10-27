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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode* ans;
        unordered_map<TreeNode*, TreeNode*> H;

        deque<TreeNode*> Q;
        Q.push_back(root);

        while(Q.size() > 0)
        {
            auto node = Q.back();
            Q.pop_back();
            if(node->left)
            {
                H[node->left] = node;
                Q.push_back(node->left);
            }
            if(node->right)
            {
                H[node->right] = node;
                Q.push_back(node->right);
            }
        }

        H[root] = NULL;
        set<TreeNode*> S;
        while (H.find(p) != H.end())
        {
            S.insert(p);
            p = H[p];
        }

        while(find(S.begin(), S.end(), q) == S.end())
        {
            q = H[q];
        }

        return q;
    }
};
