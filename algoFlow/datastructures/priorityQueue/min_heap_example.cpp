#include "../../../debug.h"

/*
 * By default priority queue in C++ gets the maximum
 * To get minimum, the following ways can be used.
 */

void method2()
{
    //  Inserting values by changing their sign (using minus (-) for positive number and using plus (+) for negative number :
    priority_queue<int>pq2;
    pq2.push(-1); //for +1
    pq2.push(-2); //for +2
    pq2.push(-3); //for +3
    pq2.push(4);  //for -4

    while(!pq2.empty())
    {
        int r = pq2.top();
        pq2.pop();
        cout<<-r<<" ";
    }

}

struct compare
{
    bool operator()(const int & a, const int & b)
    {
        return a>b;
    }
};


void method3()
{
    priority_queue<int,vector<int>,compare> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);

    while(!pq.empty())
    {
        int r = pq.top();
        pq.pop();
        cout<<r<<" ";
    }
}


int main()
{
    priority_queue<int,vector<int>,greater<int> >pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);

    while(!pq.empty())
    {
        int r = pq.top();
        pq.pop();
        cout<<r<< " ";
    }
    return 0;
}
