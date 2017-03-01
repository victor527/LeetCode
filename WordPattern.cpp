#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
#include <map>
#include <unordered_set>

using namespace std;

bool wordPattern(string pattern, string str) {
    istringstream input(str);
    string s;
    vector<string> v;
    while(input >> s)
        v.push_back(s);
    if(v.size() != pattern.size()) return false;
    map<string, char> s2c;
    map<char, string> c2s;
    for(int i = 0; i < v.size(); i++){
        if(s2c[v[i]] == 0 && c2s[pattern[i]] == ""){
            s2c[v[i]] = pattern[i];
            c2s[pattern[i]] = v[i];
        }
        else if(s2c[v[i]] != pattern[i]) return false;
    }
    return true;
}

int main(){
    auto t_start = chrono::high_resolution_clock::now();
    string pattern = "abba", str = "dog cat cat dog";
    bool result = wordPattern(pattern, str);
    cout << result << endl;
    auto t_end = chrono::high_resolution_clock::now();
    cout << "Wall clock time passed: " << chrono::duration<double, milli>(t_end-t_start).count() << " ms\n";
    return 0;
}



