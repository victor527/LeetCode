#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <chrono>
#include <ctime>
#include <set>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0) return 0;
        if(n <= 2) return int(pow(k, n));
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // base case
        dp[0][0] = dp[0][1] = k;
        dp[1][0] = k * (k - 1);
        dp[1][1] = k;
        for(int i = 2; i < n; i++){
            dp[i][0] = (k - 1) * (dp[i - 1][0] + dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0];
        }
        return dp[n - 1][0] + dp[n - 1][1];
    }
};

int main(){
    auto t_start = chrono::high_resolution_clock::now();
    int n = 3;
    int k = 3;    
    Solution sol;
    int result = sol.numWays(n, k);
    cout << result << endl;
    auto t_end = chrono::high_resolution_clock::now();
    cout << "Wall clock time passed: " << chrono::duration<double, milli>(t_end-t_start).count() << " ms\n";
    return 0;
}