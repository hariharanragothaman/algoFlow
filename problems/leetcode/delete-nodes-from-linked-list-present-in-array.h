/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* modifiedList(vector<int>& A, ListNode* head)
    {
        ListNode* prev = new ListNode(0);
        ListNode* curr = head;
        prev->next = curr;
        ListNode* prev2 = prev;

        unordered_set<int> S;
        for(auto c: A)
            S.insert(c);

        while(curr != NULL)
        {
            auto tmp = curr->val;
            if(S.find(tmp) != S.end())
            {
                prev2->next = curr->next;
            }
            else
            {
                prev2 = curr;
            }
            curr = curr->next;
        }

        return prev->next;
    }
};
