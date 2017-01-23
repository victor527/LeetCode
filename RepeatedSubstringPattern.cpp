#include <iostream>
#include <string>
#include <vector>

using namespace std;

    bool repeatedSubstringPattern(string str)
    {
        vector<int> dp(str.size() + 1, 0);
        int i = 1, j = 0;
        while(i < str.size())
        {
            if(str[i] == str[j])
                dp[++i] = ++j;
            else if(j == 0)
                i++;
            else
                j = dp[j];
        }
        return dp[str.size()] && dp[str.size()]%(str.size()-dp[str.size()]) == 0;
    }


