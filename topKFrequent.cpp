#include <iostream>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        int max = 0;
        int value;
        vector<int> result;
        for(int j = 0; j < k; j++){
            for(auto it = mp.begin(); it != mp.end(); it++){
                if(it->second > max){
                    max = it->second;
                    value = it->first;
                }
            }
            max = 0;
            mp.erase(value);
            result.push_back(value);
        }
        return result;
    }
};


int main(){
    vector<int> input = {1,1,2,3,1,3,4,1,4,4,3};
    int k = 2;
    vector<int> result;
    Solution sol;
    result = sol.topKFrequent(input, k);

    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}