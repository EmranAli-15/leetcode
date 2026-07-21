#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        if(n > 1)
        {
            if(nums[0] != nums[1]) return nums[0];
        }

        for(int i=1; i<n-1; i++)
        {
            if(n==1) return nums[0];
            else if((nums[i] != nums[i+1]) && (nums[i] != nums[i-1])) return nums[i];
        }
        return nums[n-1];
    }
};

int main()
{
    vector<int> a = {4,1,2,1,2};
    // 1 1 2 2 4
    vector<int> b = {2,2,1};
    // 1 2 2
    vector<int> c = {1};
    // 1

    Solution s;
    cout << s.singleNumber(a) << endl;
    cout << s.singleNumber(b) << endl;
    cout << s.singleNumber(c) << endl;


    return 0;
}

