/*
 *  Segment Tree Implementation
 *
 *  References: https://codeforces.com/blog/entry/1256
 *  Notes: This is also called as interval tree
 *
 */

#include "../../../debug.h"

class SegmentTree
{
private:
    vector<int> segment_tree;
    int n;
public:
    void build_tree(vector<int>& arr)
    {
        n = arr.size();
        segment_tree.resize(2*n);
        for(int i=0; i<n; i++)
            segment_tree[i+n] = arr[i];

        for(int i=n-1; i>0; i--)
            // The operation here should be replaced by the function of intent
            segment_tree[i] = segment_tree[i*2] + segment_tree[i*2+1];

        cout <<"Printing the built segment Tree" << endl;
        for(auto c: segment_tree)
            cout << c << " ";
        cout << endl;
    }

    void update(int position, int value)
    {
        position += n;
        segment_tree[position] = value;
        while(position > 1)
        {
            position = position >> 1;
            // The operation here should be replaced by the function of intent
            segment_tree[position] = segment_tree[position*2] + segment_tree[position*2+1];
        }
    }

    int query(int left, int right)
    {
        cout << "Entering function to query" << endl;
        left = left + n;
        right = right + n;
        int result = 0;

        while(left <= right)
        {
            if(left % 2 == 1)
            {
                if(result == 0)
                    result = segment_tree[left];
                else
                    // The operation here should be replaced by the function of intent
                    result = result + segment_tree[left];
            }
            if(right % 2 == 0)
            {
                if(result == 0)
                    result = segment_tree[right];
                else
                    // The operation here should be replaced by the function of intent
                    result = result + segment_tree[right];

            }
            left = (left + 1) >> 1;
            right = (right - 1) >> 1;
        }
        return result;
    }

};


int main()
{
    vector<int> arr {0, 1, 1, 0, 0, 1, 1, 0};
    SegmentTree seg_obj;
    seg_obj.build_tree(arr);
    seg_obj.update(4, 7);
    int ans = seg_obj.query(0, 4);
    cout << "The answer is: " << ans << endl;
    return 0;
}
