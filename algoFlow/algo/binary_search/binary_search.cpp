#include "../../../debug.h"
using namespace std;

/*
 *  Reference: https://codeforces.com/blog/entry/96699
 *  1. The main idea behind binary search is linear-reduction of search space.
 */

int find_position_basic(const vector<int> A, int x)
{
    int n = A.size();
    int l = 0;
    int r = (int)A.size() -1;                       // [l, r] is our search space

    while(l <= r)                                   // search space is non-empty
    {
        int pivot = l + (r-l) / 2;                  // "middle" position in the range
        if(A[pivot] == x)
            return pivot;                           // found!
        else if(A[pivot] < x)
            l = pivot + 1;                          // remove all indices <= m from the search space
        else
            r = pivot - 1;                          // remove all indices >= m from the search space
    }

    return n;                                       // Element not found.
}


/*
 *  More general idea
 *
 *  1.  We were using some kind of ordering (the ordering of integers, in our example)
 *      to discard a large part of the search space
 *      (in fact, we discarded about half the search space each time).
 *
 *  2.  How do we generalize this further?
 *      More importantly, what will be the statement of the generalized problem?
 *
 *  3.
 */


int find_first_false(const vector<bool>& b)
{
    int l = -1;
    int r = (int)b.size();

    while(r-l > 1)
    {
        int pivot = l + (r-l) / 2;
        if(b[pivot])
            l = pivot;
        else
            r = pivot;
    }
    return r;
}


/*
 *  1.  But, we said earlier that we won't really construct 𝑏 in our code, right?
 *      How do we use this same algorithm for solving our own problem?
 *
 *  2. Note that, by what we said earlier, 𝑏[𝑖] is just defined as the truth value of 𝑎[𝑖]<𝑥,
 *     so computing it on the fly is no big deal.
 *     So, if we replace 𝑏[𝑚] with 𝑎[𝑚]<𝑥, that would solve our problem.
 *
 *  3. Rather than explicitly reason using the order < and the value x,
 *     we constructed an array 𝑏 of some very specific form
 *     (the first few things in it being true and the rest being false),
 *     and found the location of the first false in b.
 *
 */

/*
 *  The generalization
 *
 *  Suppose we are given the following:

    [𝑙,𝑟]: a range of integers (in our example, [0,𝑛−1])
    𝑓: a function from integers to booleans, which satisfies the following property:
        there exists some integer 𝑡 such that for all 𝑙≤𝑥<𝑡, 𝑓(𝑥) is true, and for all 𝑡≤𝑥≤𝑟, 𝑓(𝑥) is false.
    Then if the time taken to compute 𝑓 is upper bounded by 𝑇(𝑙,𝑟), we can find the value of 𝑡 (i.e., the first false index) in 𝑂(𝑇(𝑙,𝑟)log2(𝑟−𝑙+1))+𝑂(1) time.
    Such an 𝑓 is called a predicate. In the problem we discussed above, 𝑓 is called a predicate.
 */

template <class Integer, class F>
Integer find_first_false(Integer l, Integer r, F&& f)
{
    --l;
    ++r;
    while (r - l > 1) {
        Integer m = l + (r - l) / 2; // prefer std::midpoint in C++20
        if (f(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

/*
 * Note that this implementation also has the nice property that
 * 𝑙 is the position of the last true in the corresponding array 𝑏,
 * so you can define a function similar to this one that returns 𝑙 instead.
 */

int find_position(const vector<int>& a, int x)
{
    auto f = [&](int i) { return a[i] < x; };
    int n = (int)a.size();
    int pos = find_first_false(0, n - 1, f);
    if (pos == n || a[pos] != x) return n;
    return pos;
}

/*
 * Note that this abstraction also gives us the following result:
 * we don't really need 𝑎 to be sorted at all.
 * The only thing we need is that everything less than 𝑥 in 𝑎 should be in a prefix,
 * and everything not less than 𝑥 should be in the remaining suffix and if 𝑥 is in the array,
 * the beginning of that suffix should have 𝑥 at it.
 * This definition also handles possible duplicates of 𝑥 in the array.
 */

int main()
{

}
