#include "../../../../debug.h"


/*
        Crux point 1:
        Some key points related to segment tree solution
        If we fill the bucket in the reverese order i.e., traversing nums from right to left,
        we just need to find sum of all the elements in bucket[0 to nums[i]+offset-1]

        Crux Point 2:
        number of elements smaller than 5 is just sum(0, 4)

        So:
        1. Traverse the array from right to left
        2. Now, create a frequency bucket - arr
            This is the array you need to segment tree
        3. For the element of interest calcuclate sum(0, element-1)
        4. Now as you come to the next element update the bucket.

        So we need to constantly need to keep updating the frequency bucket ~ That's the key here
        --------------------------------------------------------------------------------------------

*/

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
    }

    void update(int& position, int& value)
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
        // cout << "Entering function to query: " << left << " " << right << endl;
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
        // cout << "The query for the result is: " << result << endl;
        return result;
    }

};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        /* to account for negative numbers adding a big offset */
        int offset = 1e4;
        for(int i=0; i<nums.size(); i++)
            nums[i] += offset;

        SegmentTree seg_obj;
        int sz = pow(2, 15);
        vector<int> frequency;
        frequency.resize(2*sz, 0);
        seg_obj.build_tree(frequency);


        int n = nums.size();
        vector<int> answer;

        reverse(nums.begin(), nums.end());
        int tmp = 0;

        for(int i=0; i<n; i++)
        {
            // cout << "The nums[i] is:" << nums[i] << endl;
            tmp = nums[i] -1;
            // cout << "The value of tmp is:" << tmp << endl;
            frequency[nums[i]] += 1;
            seg_obj.update(nums[i], frequency[nums[i]]);
            int ss = seg_obj.query(0, tmp);
            answer.emplace_back(ss);
            // cout << "*********************************" << endl;
        }


        reverse(answer.begin(), answer.end());
        return answer;
    }
};

int main()
{
    return 0;
}
