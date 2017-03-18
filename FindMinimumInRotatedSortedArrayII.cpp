#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] < nums[i - 1]){
                return nums[i];
            }
        }
        return nums[0];
    }
};

int main(){
    vector<int> grid = {4, 5, 6, 7, 0, 1, 2};
    Solution sol;
    int result = sol.findMin(grid);
    cout << result << endl;
    return 0;
}