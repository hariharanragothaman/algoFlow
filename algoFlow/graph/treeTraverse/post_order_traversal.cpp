#include "../../../debug.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void postOrder(TreeNode* root)
{
    vector<TreeNode*> postOrder;
    unordered_map<TreeNode*, TreeNode*> P;

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
            P[node->left] = node;
            St.push_back(node->left);
        }
        if(node->right)
        {
            P[node->right] = node;
            St.push_back(node->right);
        }
    }
    reverse(postOrder.begin(), postOrder.end());
}

int main()
{
    return 0;
}
