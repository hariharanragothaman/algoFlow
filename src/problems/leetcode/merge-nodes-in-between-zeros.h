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
    ListNode* result = new ListNode(0);
    ListNode* tmp = result;
public:
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode* current = head;
        int value = 0;
        while(current != NULL)
        {
            if(current->val == 0 and value != 0)
            {
                result->next = new ListNode(value);
                result = result->next;
                value = 0;
            }
            if(current->val != 0)
            {
                value += current->val;
            }
            current = current->next;
        }
        return tmp->next;
    }
};
