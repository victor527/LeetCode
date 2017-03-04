#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void permutation(vector<vector<int> >& result, vector<int>& nums, int begin){
	if(begin == nums.size()){
		result.push_back(nums);
		return;
	}

	for(int i = begin; i < nums.size(); i++){
		swap(nums[i], nums[begin]);
		permutation(result, nums, begin + 1);
		swap(nums[i], nums[begin]);
	}
}

vector<vector<int> > permute(vector<int>& nums){
	vector<vector<int> > result;
	permutation(result, nums, 0);
	return result;
}


int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    cout<< nums[1] << endl;
    vector<vector<int> > result = permute(nums);
    cout<< result.size() << endl;
    cout<< result[1].size() << endl;
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[0].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout<< "success!" << endl;
    return 0;
}