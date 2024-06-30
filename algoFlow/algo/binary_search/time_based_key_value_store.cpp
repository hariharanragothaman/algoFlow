class TimeMap
{
private:
    unordered_map<string, vector<pair<int, string>>> H;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        pair<int, string> p = make_pair(timestamp, value);
        H[key].push_back(p);
    }

    string get(string key, int t)
    {
        // This line should be reference, as copying a vector is O(n)
        vector<pair<int, string>> &A = H[key];
        int l = 0;
        int r = A.size() - 1;

        while(l <= r)
        {
            int p = l + (r-l) / 2;

            if(A[p].first > t)
            {
                r = p - 1;
            }
            else if(A[p].first <= t)
            {
                l = p + 1;
            }
        }

        return (l==0) ? "" : A[l-1].second;
    }
};

/**
Testcase
Run Code Result
Debugger

 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
