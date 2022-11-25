#include "bits/stdc++.h"
#include "../../../debug.h"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode* root)
{

    vector<int> post_order;
    vector<int> res_tmp;

    deque<TreeNode*> q;
    q.emplace_back(root);

    TreeNode* node;

    if(root== nullptr)
        return post_order;

    while(q.size() > 0)
    {
        node = q.back();
        q.pop_back();
        /* This line can be replaced to just add node value as well */
        res_tmp.emplace_back(node->val);
        if(node->left)
            q.emplace_back(node->left);
        if(node->right)
            q.emplace_back(node->right);
    }
    while(res_tmp.size() > 0)
    {
        post_order.emplace_back(res_tmp.back());
        res_tmp.pop_back();
    }
    return post_order;
}

vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> pre_order;

    deque<TreeNode*> q;
    q.emplace_back(root);

    TreeNode* node;

    if(root == nullptr)
        return pre_order;

    while(q.size() > 0)
    {
        node = q.back();
        q.pop_back();
        /* This line can be replaced to just add node value as well */
        if(node != nullptr)
        {
            pre_order.emplace_back(node->val);
            if(node->right)
                q.emplace_back(node->right);
            if(node->left)
                q.emplace_back(node->left);
        }
    }


    return pre_order;

}
