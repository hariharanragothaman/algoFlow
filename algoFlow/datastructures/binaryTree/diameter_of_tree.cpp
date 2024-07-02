#include "../../../debug.h"
using namespace std;

// Refer: https://leetcode.com/problems/diameter-of-binary-tree/

/*
 * Definition for a binary tree node.
 */

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
    int diameterOfBinaryTree(TreeNode* root)
    {
        int max_length = 0, result = 0;
        unordered_map<TreeNode*, vector<TreeNode*>> G;

        TreeNode* current = root;

        TreeNode* select;
        deque<pair<TreeNode*, int>> Q, Q2;
        Q.push_back({current, 0});

        while(Q.size() > 0)
        {
            auto [node, l] = Q.back();
            Q.pop_back();

            if(l > max_length)
            {
                max_length = l;
                select = node;
            }

            int tmp = l + 1;
            if(node->left)
            {
                Q.push_back({node->left, tmp});

                /* Creating the graph */
                G[node].push_back(node->left);
                G[node->left].push_back(node);
            }

            if(node->right)
            {
                Q.push_back({node->right, tmp});

                /* Creating the graph */
                G[node].push_back(node->right);
                G[node->right].push_back(node);
            }
        }

        set<TreeNode*> V;
        Q2.push_back({select, 0});

        while(Q2.size() > 0)
        {
            auto [node, l] = Q2.back();
            Q2.pop_back();
            V.insert(node);
            result = max(result, l);
            int tmp = l + 1;
            for(auto c: G[node])
            {
                if(find(V.begin(), V.end(), c) == V.end())
                    Q2.push_back({c, tmp});
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}
