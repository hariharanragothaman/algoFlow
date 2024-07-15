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

// Functor
struct Compare
{
    bool operator()(vector<int> A, vector<int> B)
    {
        if(A[0] != B[0])
        {
            return A[0] < B[0];
        }
        else
        {
            return A[2] > B[2];
        }
    }
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& D)
    {
        unordered_map<int, vector<pair<int, int>>> G;
        sort(D.begin(), D.end(), Compare());
        int n = static_cast<int>(D.size());

        unordered_map<int, int> P;

        for(int i=0; i<n; i++)
        {
            G[D[i][0]].push_back({D[i][1], D[i][2]});
            P[D[i][1]] = D[i][0];
        }

        // Find the root
        set<int> values;
        for(auto c: P)
        {
            values.insert(c.second);
        }

        int root{};
        for(auto c: values)
        {
            if(P.find(c) == P.end())
            {
                root = c;
                break;
            }
        }

        cout << "root is: " << root << endl;
        TreeNode* ans = new TreeNode(root);

        deque<TreeNode*> Q;
        Q.push_back(ans);
        set<TreeNode*> S;

        while(!Q.empty())
        {
            auto node = Q.back();
            // cout << "The node value is: " << node->val << endl;
            Q.pop_back();
            vector<pair<int, int>> children = G[node->val];
            node->left = nullptr;
            node->right = nullptr;
            for(auto c: children)
            {
                if(c.second == 1)
                {
                    node->left = new TreeNode(c.first);
                }
                else if(c.second == 0)
                {
                    node->right = new TreeNode(c.first);
                }
            }
            if(S.find(node->left) == S.end() and node->left != nullptr)
                Q.push_back(node->left);
            if(S.find(node->right) == S.end() and node->right != nullptr)
                Q.push_back(node->right);

        }
        return ans;
    }
};
