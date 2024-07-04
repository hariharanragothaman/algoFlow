#include "../../../debug.h"

/*
 * The std::priority_queue is a reduced std::queue. It needs the header <queue>.
 *
 *
 * The difference to the std::queue is, that their biggest element is always at the top of the priority queue.
 * std::priority_queue pri uses by default the comparison operator std::less.
 *
 * Similar to std::queue, pri.push(e) inserts a new element e into the priority queue.
 * pri.pop() removes the first element of the pri, but does that with logarithmic complexity.
 * With pri.top() you can reference the first element in the priority queue, which is the greatest one.
 * The std::priority_queue knows its size, but did not support the comparison operator on their instances.
 */

/*
 *  Important:
 *  Binary_heap uses vector<> as the default container.
 *    // data-type, container, Comparator function
    priority_queue< pair<int, int>, vector<pair<int, int>>, Compare> B;
 *
 */

struct MinTop
{
    bool operator()(const int a, const int b)
    {
        return a > b;
    }
};

struct MaxTop
{
    bool operator()(const int a, const int b)
    {
        return a < b;
    }
};


int main()
{
    priority_queue<int, vector<int>, MinTop> PQ2;
    PQ2.push(1);

    while(!PQ2.empty())
    {
        cout << PQ2.top() << endl;
        PQ2.pop();
    }

    /*
     * This is equivalent of priority_queue<int, vector<int>, less> pq;
     * (or) in this case, MaxTop()
     *
     */
    priority_queue<int> pq;

    pq.emplace(5);
    pq.emplace(10);
    pq.emplace(100);

    /* PQ always get the greatest by default*/
    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }

    std::priority_queue<int> myPriorityQueue;

    std::cout << "is empty:\t" << myPriorityQueue.empty() << std::endl;   // 1 (denotes true)
    std::cout << "size:\t\t" << myPriorityQueue.size() << std::endl;    // 0

    myPriorityQueue.push(3);
    myPriorityQueue.push(1);
    myPriorityQueue.push(2);
    std::cout << "top:\t\t" << myPriorityQueue.top() << std::endl;     // 3

    std::cout<< "Data:\t";
    while (!myPriorityQueue.empty()){
        std::cout << myPriorityQueue.top() << " ";
        myPriorityQueue.pop();
    }                                                    // 3 2 1
    std::cout << std::endl;

    std::cout << "is empty:\t" << myPriorityQueue.empty() << std::endl;   // 1 (denotes true)
    std::cout << "size:\t\t" << myPriorityQueue.size() << std::endl;    // 0

    std::priority_queue<std::string, std::vector<std::string>,
    std::greater<std::string>> myPriorityQueue2;

    myPriorityQueue2.push("Only");
    myPriorityQueue2.push("for");
    myPriorityQueue2.push("testing");
    myPriorityQueue2.push("purpose");
    myPriorityQueue2.push(".");

    while (!myPriorityQueue2.empty()){
        std::cout << myPriorityQueue2.top() << " ";
        myPriorityQueue2.pop();
    }

    return 0;
}
