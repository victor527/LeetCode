#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <chrono>
#include <ctime>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Trial 1 with new copy with Time complexity of O(N) and space O(N)
    /*void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newNums(n);
        for(int i = 0; i < n; i++)
            newNums[i] = nums[i];
        for(int i = 0; i < n; i++)
            nums[(i+k)%n] = newNums[i];
    }*/

    // Trial 2 with only Time Complexity of O(N) and space of O(1)
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
    
        // Reverse the first n - k numbers.
        // Index i (0 <= i < n - k) becomes n - k - i.
        reverse(nums.begin(), nums.begin() + n - k);
        
        // Reverse tha last k numbers.
        // Index n - k + i (0 <= i < k) becomes n - i.
        reverse(nums.begin() + n - k, nums.begin() + n);
        
        // Reverse all the numbers.
        // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
        // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
        reverse(nums.begin(), nums.begin() + n);
    }
};

int main(){
    auto t_start = chrono::high_resolution_clock::now();
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};
    int n = 56;
    cout << "hello" << endl;
    sol.rotate(nums, n);
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    auto t_end = chrono::high_resolution_clock::now();
    cout << "Wall clock time passed: " << chrono::duration<double, milli>(t_end-t_start).count() << " ms\n";
    return 0;
}



