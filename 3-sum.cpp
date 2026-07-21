#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        unordered_map<int, int> stored;

        for(int i=0; i<n; i++)
        {
            if(i>0 && nums[i]==nums[i-1]) {cout << "hello\n";continue;}

            int c = i;

            int a = 0;
            int b = n-1;

            int x = stored[nums[a]];
            int y = stored[nums[b]];

            if(x==1 || y==1) continue;

            while(a<b)
            {

                if(a==c)
                {
                    a++;
                    continue;
                }
                if(b==c)
                {
                    b--;
                    continue;
                }

                int sum = nums[a]+nums[b]+nums[c];

                if(sum == 0)
                {
                    ans.push_back({nums[c], nums[a], nums[b]});
                    cout << nums[c] << " " << nums[a] << " " << nums[b] << endl;
                    stored.insert({nums[a], 1});
                    stored.insert({nums[b], 1});
                    break;
                }
                else if(sum > 0) b--;
                else a++;

            }
        }

        return ans;
    }
};

int main()
{
    vector<int> x = {-1,0,1,2,-1,-4};
    //vector<int> x = {-1,0,1};
    //vector<int> x = {0,0,0};
    //vector<int> x = {0,0,0,0};
    Solution s;

    vector<vector<int>> y = s.threeSum(x);

    for(int i=0; i<y.size(); i++)
    {
        //cout << y[i][0] << " " << y[i][1] << " " << y[i][2] << endl;
    }

    return 0;
}
