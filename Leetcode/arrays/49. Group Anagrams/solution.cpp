#include <vector>
#include<array>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isAnagram(string t, string s)
    {

        if (t.length() != s.length()) return false;
        
        int letters[26] = {0};

        for (int i = 0; i < t.length(); i++)
        {
            letters[t.at(i) - 'a']++;
            letters[s.at(i) - 'a']--;

        }
        for(int i : letters)
        {
            if (i !=0)
            {
                return false;
            }
            
        }
        return true;
} 
};

int main()
{
    Solution sol;
    string s = "hasala";
    string t = "hasala";

    cout << sol.isAnagram(s, t) << endl; 
    return 0;
}