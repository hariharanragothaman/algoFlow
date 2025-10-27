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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> A = {};
        if(!root) return A;

        A.push_back({root->val});

        deque<TreeNode*> Q;
        Q.push_back(root);

        while(!Q.empty())
        {
            int n = static_cast<int>(Q.size());
            vector<int> tmp = {};
            for(int i=0; i<n; i++)
            {
                auto c = Q.front();
                Q.pop_front();

                if(c->left)
                {
                    Q.push_back(c->left);
                    tmp.push_back(c->left->val);

                }
                if(c->right)
                {
                    Q.push_back(c->right);
                    tmp.push_back(c->right->val);
                }
            }
            if(tmp.size() > 0)
                A.push_back(tmp);
        }

        return A;
    }
};
