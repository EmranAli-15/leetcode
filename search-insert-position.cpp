#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};



int main()
{

    vector<int> a = {11,21,31,41,51,61,71,81,91,101};

    Solution s;
    cout << s.searchInsert(a, 510);


    return 0;
}
