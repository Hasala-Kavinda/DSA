#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (mp.count(nums[i]))
            {
                if (abs(i - mp[nums[i]]) <= k)
                    return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    cout << sol.containsNearbyDuplicate(nums, k) << endl; 
    return 0;
}