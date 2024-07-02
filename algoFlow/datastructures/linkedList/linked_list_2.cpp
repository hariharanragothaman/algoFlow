#include "../../../debug.h"

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int sum(ListNode *head)
{
    ListNode* current = head;
    long long total = 0;
    while(current != NULL)
    {
        total += current->val;
        current = current->next;
    }
    return total;

}

int length(ListNode *head)
{
    ListNode* current = head;
    long long total = 0;
    while(current != NULL)
    {
        total++;
        current = current->next;
    }
    return total;
}

void PrintReverse(ListNode *head)
{
    ListNode* prev = nullptr;
    ListNode* current = head;

    while(current != nullptr)
    {
        // Preserving the remaining list
        ListNode* tmp = current->next;

        // Switching the pointers
        current->next = prev;
        prev = current;

        // Moving to the next one.
        current = tmp;
    }

    // Linkedlist has been reversed
    ListNode* ct = prev;
    while(prev != NULL)
    {
        cout << prev->val << " ";
        prev = prev->next;
    }
    cout << "\n";
}


int hasCycle(ListNode *head)
{
    if(head == NULL)
        return false;
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(slow != fast)
    {
        if(fast == NULL || fast->next == NULL)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}


ListNode* detectCycle(ListNode* head)
{
    // Implement a function detectCycle that returns a pointer to the node where cycle starts. If there is no cycle, return null.

    if (head == NULL || head->next == NULL)
        return NULL;

    ListNode *slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;

    while (fast && fast->next)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    // If loop does not exist
    if (slow != fast)
        return NULL;

    // If loop exists. Start slow from
    // head and fast from meeting point.
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int DistanceToCycle(ListNode* head)
{
    ListNode* current = head;
    ListNode* result = detectCycle(current);
    ListNode* tmp = head;
    int res = 0;
    if(result != NULL)
    {
        while(tmp != result)
        {
            res++;
            tmp = tmp->next;
        }
        return res;
    }
    return -1;
}


ListNode *intersection(ListNode *headA, ListNode *headB)
{
    ListNode *pA = headA;
    ListNode *pB = headB;
    while (pA != pB) {
        pA = pA == nullptr ? headB : pA->next;
        pB = pB == nullptr ? headA : pB->next;
    }
    return pA;
}

ListNode* merge(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    else if (l2 == NULL) {
        return l1;
    }
    else if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}


ListNode* MiddleElement(ListNode *head)
{
    ListNode* current = head;
    long long total = 0;
    while(current != NULL)
    {
        total++;
        current = current->next;
    }

    long long middle = ceil(total/2);
    long long i = 0;
    ListNode* node = head;
    while( i < total)
    {
        if(i==middle)
            return node;
        node = node->next;
        i++;
    }
    return NULL;
}

ListNode* DeleteFirstElement(ListNode* head, int element)
{
    if (head == NULL)
        return NULL;

        // Move the head pointer to the next node
    else if(head->val == element)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* current = head;
    ListNode* previous = NULL;
    while(current->val != element)
    {
        previous = current;
        current = current->next;
    }

    if(current != NULL)
        previous->next = current->next;
    return head;
}

int CycleLength(ListNode* head)
{
    if(head == NULL)
        return 0;
    ListNode* slow=head,*fast=head;
    while(slow && fast && fast->next)
    {
        slow=slow->next; //slow pointer moves slowly
        fast=fast->next->next; //fast pointer moves fast
        if(fast==slow)
        {
            //there is loop - count loop length
            ListNode* temp=slow;
            temp=temp->next;
            int count = 1;
            while(temp!=slow)
            {
                count++;
                temp=temp->next;
            }

            return count; //return loop length
        }
    }
    return 0;//if there is no loop
}

ListNode* removeCycle(ListNode* head)
{
    ListNode* point = NULL;
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow =slow->next;
        if(fast == slow)
        {
            point = fast;
            break;
        }
    }

    if(point != NULL)
    {
        slow = head;
        while(slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        while(fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }

    return head;
}


int main()
{
    return 0;
}
