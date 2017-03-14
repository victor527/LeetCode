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
    int minCost(vector<vector<int>>& costs) {
        int num_house = costs.size();
        if(num_house == 0) return 0;
        vector<int> cost = costs[0];
        for(int i = 1; i < num_house; i++){
            int c0 = cost[0], c1 = cost[1], c2 = cost[2];
            cost[0] = min(c1, c2) + costs[i][0];
            cout << "cost[0] = "<< cost[0] << endl;
            cost[1] = min(c0, c2) + costs[i][1];
            cout << "cost[1] = "<< cost[1] << endl;
            cost[2] = min(c0, c1) + costs[i][2];
            cout << "cost[2] = "<< cost[2] << endl;
        }
        return *min_element(cost.begin(), cost.end());
    }
};

int main(){
    auto t_start = chrono::high_resolution_clock::now();
    vector<vector<int>> costs = {{1,2,3},{4,5,6},{1,3,5}};
    
    Solution sol;
    int result = sol.minCost(costs);
    cout << result << endl;
    auto t_end = chrono::high_resolution_clock::now();
    cout << "Wall clock time passed: " << chrono::duration<double, milli>(t_end-t_start).count() << " ms\n";
    return 0;
}