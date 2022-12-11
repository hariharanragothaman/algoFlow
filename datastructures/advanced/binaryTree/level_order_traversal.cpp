#include "bits/stdc++.h"
#include "../../../debug.h"

// Definition for a binary tree node.
struct TreeNode {
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
        if(!root)
        {
            return {};
        }

        vector<vector<int>> result;
        deque<TreeNode*> q;
        q.push_back(root);


        int level = 0;

        while(!q.empty())
        {
            result.push_back({});
            int n = q.size(); // This line is very key - since - in C++ i we include it in the loop, it recomputes it

            for(int i=0; i < n; i++)
            {
                // Returns a reference to the front element
                TreeNode *node = q.front();
                // Pops the first element
                q.pop_front();
                result[level].push_back(node->val);


                if(node->left)
                    q.push_back(node->left);
                if(node->right)
                    q.push_back(node->right);

            }

            level = level + 1;
        }

        return result;
    }
};

int main()
{
    return 0;
}
