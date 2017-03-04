#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for(int i = 0;i < nums.size(); i++)
    {
        for(int j = i+1;j < nums.size(); j++)
        {
            if(nums[i] + nums[j] == target)
            {
                result.push_back(i);
                result.push_back(j);
                return result;                    
            }
        }
    }
    return result;
}

int main(){
	vector<int> nums;
	vector<int> result;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	result = twoSum(nums, 9);
	for(int i = 0; i<result.size();i++){
		cout << result[i];
	}
	return 0;
}