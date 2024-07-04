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
    vector<int> rightSideView(TreeNode* root)
    {
        vector<vector<int>> A = {};
        if(!root)
            return {};

        deque<TreeNode*> Q;
        Q.push_back(root);

        while(!Q.empty())
        {
            int n = static_cast<int>(Q.size());
            vector<int> tmp = {};

            for(int i=0; i<n; i++)
            {
                auto node = Q.front();
                Q.pop_front();
                tmp.push_back(node->val);

                if(node->left) Q.push_back(node->left);
                if(node->right) Q.push_back(node->right);

            }
            if(tmp.size() > 0)
                A.push_back(tmp);
        }


        vector<int> result = {};
        for(auto c: A)
            result.push_back(c.back());
        return result;
    }
};
