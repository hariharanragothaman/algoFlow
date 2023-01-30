#include "../../../debug.h"

/*
 *  It can be used to declare indexers
 *  It can be used to refer to the current class instance variable.
 *  It can be used to pass the current object as a parameter to another method
 */

class Node
{
private:
    int data;
    Node* next;

public:
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};


int main()
{
    Node* n = new Node(5);
    return 0;
}
