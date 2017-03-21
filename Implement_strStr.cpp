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
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(!n)
            return 0;
        int j;
        int i = n - 1;
        while(i < m){
            for(j = n - 1; j >= 0; j--)
            {
                if(haystack[i] != needle[j]){
                    break;
                }
            }
            if(j == n){
                return i;
            }else{
                i = j 
            }
        }
        return -1;
    }
};

int main(){
    auto t_start = chrono::high_resolution_clock::now();
    string haystack = "HERE IS A SIMPLE EXAMPLE";
    string needle = "EXAMPLE";
    Solution sol;
    int v = sol.strStr();
    cout << v << endl;
    auto t_end = chrono::high_resolution_clock::now();
    cout << "Wall clock time passed: " << chrono::duration<double, milli>(t_end-t_start).count() << " ms\n";
    return 0;
}



