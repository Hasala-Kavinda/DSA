// time complexity : O(n log n)
#include <vector>
#include<array>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());

            mp[temp].push_back(strs[i]);
        }

        for (auto i : mp)
        {
            res.push_back(i.second);
        }
        return res;
    }
};

int main()
{
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution;

    vector<vector<string>> result;
    result = solution.groupAnagrams(input);

    for (const auto &group : result)
    {
        for (const string &str : group)
        {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}