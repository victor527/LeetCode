#include <iostream>
#include <vector>

using namespace std;

// Solution 1 Brute Force Time Complexity = O(n^3)
/*class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                for(int k = j + 1; k < nums.size(); k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        result.push_back(v);
                    }
                }
            }
        }
        return result;
    }
};*/

// Solution 2 Use a target to store the mid point of the number and use two pointer from start point and the end point to find the three sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int front = i + 1;
            int back = nums.size() - 1;
            int target = -nums[i];
            while(front < back){
                int sum = nums[front] + nums[back];
                if(sum < target)
                    front++;
                else if(sum > target)
                    back--;
                else{
                    vector<int> threeNum(3, 0);
                    threeNum[0] = nums[i];
                    threeNum[1] = nums[front];
                    threeNum[2] = nums[back];
                    result.push_back(threeNum);
                    while(front < back && nums[front] == threeNum[1])
                        front++;
                    while(front < back && nums[back] == threeNum[2])
                        back--;
                }
            }
            while(i + 1 < nums.size() && nums[i+1] == nums[i])
                i++;
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    vector<vector<int>> ans;
    ans = sol.threeSum(nums);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
