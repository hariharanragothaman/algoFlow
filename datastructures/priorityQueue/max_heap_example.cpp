#include "../../debug.h"
/*
	In STL heap in general is binary max heap
	9 8 6 7 4 5 2 0 3 1

		 9
	  / 	\
	 8       6
	/ \		/ \
   7   4   5   2
  /	\ /
  0 3 1

*/

size_t leftChild(size_t index)
{
    return (index + 1) * 2 - 1;
}

size_t rightChild(size_t index)
{
    return (index + 1) * 2;
}

int main()
{
    vector<double> A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    make_heap(A.begin(), A.end());

    for(auto c: A)
    {
        cout << c << " ";
    }
    cout << endl;

    cout << "Is this a heap? " << is_heap(A.begin(), A.end()) << endl;
    auto heapUntil = std::is_heap_until(begin(A), end(A));

    /*
        Now lets talk about pushing into heaps and so on...
    */
    A.push_back(8.8);
    push_heap(begin(A), end(A)); // This makes it bubble it's way to the top....
    cout << "After Pushing back..." << endl;
    for(auto c: A)
    {
        cout << c << " ";
    }
    cout << endl;

    pop_heap(begin(A), end(A)); // Swaps the element we want in top of the heap with last element.
    double result = A.back();
    cout << "The value that is going to be popped is: " << result << endl;
    A.pop_back();

    cout << "After Popping back..." << endl;
    for(auto c: A)
    {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
