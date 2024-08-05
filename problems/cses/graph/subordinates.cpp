/*
    செயல் பேசும் ஆழம் இங்கே சொற்கள் பேசுமா?
    Focus, Determination and Sheer-Will
    The woods are lovely, dark and deep,
    But I have promises to keep,
    And miles to go before I sleep,
    And miles to go before I sleep.

    ---------------------------------------------
    1. Remember the data-type of the I/P's you are getting
    2. Function calls are not free.

*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#include "bits/stdc++.h"
#include <sys/stat.h>
using namespace std;
#endif

#define FAST_IO() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long
#define endl '\n'

/*
 *  FUNCTIONS FOR DEBUGGING
 */

inline bool fileExists (const std::string& name)
{
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

template<typename T>
void debug(const T& msg)
{
    if(fileExists("data.in"))
        cout << msg << endl;
}

void debug2()
{
    if(fileExists("data.in"))
        cout << string(25, '-') << endl;
}


void debug3()
{
    cout <<  string(25, '*') << endl;
}

template <typename T>
void print(std::vector<T> const &v)
{
for (auto i: v)
cout << i << ' ';
cout << endl;
}

template <typename T>
void quick_remove_at(vector<T> &A, typename vector<T> ::iterator it)
{
    if(it != end(A))
    {
        *it = move(A.back());
        A.pop_back();
    }
}

template <typename T>
void quick_remove_at(std::vector<T> &A, std::size_t idx)
{
    if (idx < A.size())
    {
        A[idx] = std::move(A.back());
        A.pop_back();
    }
}

class Solution
{
private:
    unordered_map<int, int> ans;
public:
    void recurse(unordered_map<int, vector<int>>& G, int start)
    {
        for(auto c: G[start])
        {
            recurse(G, c);
            ans[start] += ans[c] + 1;
        }
    }

    void post_order(unordered_map<int, vector<int>>& G)
    {
        int root = 1;
        vector<int> postorder{};
        vector<int> st;
        st.push_back(root);

        while(!st.empty())
        {
            auto node = st.back();
            st.pop_back();
            if(node)
                postorder.push_back(node);
            for(auto child: G[node])
                st.push_back(child);
        }
        reverse(postorder.begin(), postorder.end());
        for(auto node: postorder)
        {
            ans[node] += G[node].size();
            for(auto child: G[node])
                ans[node] += ans[child];
        }
    }

    void solve()
    {
        int n;
        cin >> n;
        unordered_map<int, vector<int>> G;
        for(int i=1; i<=n; i++)
            G[i] = {};

        for(int i=1; i<=n; i++)
            ans[i] = 0;

        int parent{};
        for(int i=2; i<=n; i++)
        {
            cin >> parent;
            G[parent].push_back(i);
        }

//        recurse(G, 1);
        post_order(G);
        for(int i=1; i<=n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
};


int32_t main()
{
    auto start = std::chrono::high_resolution_clock::now();

    FAST_IO();
    int T = 1;
//    cin >> T;

    Solution sol;
    while(T--)
    {
        sol.solve();
        debug2();
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

#ifndef ONLINE_JUDGE
    if(fileExists("data.in"))
    {
        cout << "Time taken: ";
        cout << duration.count() << " ms" << endl;
    }
#endif

    return 0;
}
