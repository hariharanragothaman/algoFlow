#include "../../../debug.h"

class Node
{
public:
    int data;
    Node *next;
};

void display_list(Node* node)
{
    while(node != nullptr)
    {
        cout << node->data << endl;
        node = node->next;
    }
}

void push(Node* head, int value)
{
    Node* tmp = new Node();
    tmp->data = value;
    tmp->next = head;
    head = tmp;
}

void push_at_specific_position(Node* head, int pos, int value)
{
    Node* prev = new Node();
    Node* current = new Node();
    Node* tmp = new Node();
    current = head;
    for(int i=0; i<pos; i++)
    {
        prev = current;
        current = current->next;
    }
    tmp->data = value;
    prev->next = tmp;
    tmp->next = current;
}

Node* removeNthFromEnd(Node* head, int n)
{
    int length = 0;
    Node* current = head;
    if(current->next == nullptr)
        length = 1;
    else
    {
        length = 0;
        while(current != nullptr)
        {
            current = current->next;
            length++;
        }
    }
    int candidate = length - n;
    /* Actual logic to delete */
    Node* prev;
    Node* current2 = head;

    if(candidate == 0)
    {
        head=head->next;
        return head;
    }
    for(int i=0; i<candidate; i++)
    {
        prev = current2;
        current2 = current2->next;
    }
    prev->next = current2->next;
    return head;
}

void delete_first(Node* head)
{
    Node* tmp = new Node();
    tmp = head;
    head = head->next;
    delete tmp;
}

void delete_position(Node* head, int pos)
{
    Node* current = new Node();
    Node* previous = new Node();
    current = head;

    for(int i=1; i<pos; i++)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
}

Node* middle_node(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next !=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverseList(Node* head)
{
    Node* prev = nullptr;
    Node* current = head;

    while(current != nullptr)
    {
        // Preserving the remaining list
        Node* tmp = current->next;

        // Switching the pointers
        current->next = prev;
        prev = current;

        // Moving to the next one.
        current = tmp;
    }

    return prev;
}

int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = nullptr;
    display_list(head);
    return 0;
}
