#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <chrono>
#include <ctime>
#include <set>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n){
        vector<string> result;
        string str = "";
        dfs(result, str, n, n);
        return result;
    }

    void dfs(vector<string>& result, string str, int left, int right){
        if(left == 0 && right == 0){
            result.push_back(str);
        }
        if(left > 0){
            dfs(result, str + "(" , left - 1, right);
        }
        if(right > left){
            dfs(result, str + ")", left , right - 1);
        }
    }
};

int main(){
    auto t_start = chrono::high_resolution_clock::now();
    Solution sol;
    vector<string> v = sol.generateParenthesis(5);
    //cout << v[0] << endl;
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\t"));
    cout << endl;
    auto t_end = chrono::high_resolution_clock::now();
    cout << "Wall clock time passed: " << chrono::duration<double, milli>(t_end-t_start).count() << " ms\n";
    return 0;
}



