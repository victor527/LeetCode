#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <chrono>
#include <ctime>
#include <set>
#include <unordered_map>

using namespace std;

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > results;
    unordered_map<string, multiset<string> > mp;
    for(string s:strs){
        string t = s;
        sort(t.begin(), t.end());
        mp[t].insert(s);
    }
        
    for(auto m:mp){
        vector<string> result(m.second.begin(), m.second.end());
        results.push_back(result);
    }
    
    return results;
}


int main(){
    auto t_start = chrono::high_resolution_clock::now();
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string> > result;
    result = groupAnagrams(strs);
    //cout << num << endl;
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    auto t_end = chrono::high_resolution_clock::now();
    cout << "Wall clock time passed: " << chrono::duration<double, milli>(t_end-t_start).count() << " ms\n";
    return 0;
}



