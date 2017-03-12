#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <chrono>
#include <ctime>
#include <set>
#include <unordered_map>

using namespace std;

// Trial 1 with the sort algorithm in cpp
/*bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s == t) return true;
    else return false;
}*/

// Trial 2 with hash map to see whether all the elements can cancel out.
/*bool isAnagram(string s, string t) {
    if(s.size() != t.size()) //Cases when the length of the s and t are not the same.
        return false;
    unordered_map<char, int> mp;
    for(int i = 0; i < s.size(); i++){
        mp[s[i]]++;
        mp[t[i]]--;
    }
    for(auto m: mp){
        if(m.second)
            return false;
    }
    return true;
}*/

bool isAnagram(string s, string t) {
    int num = 0;
    for(int i = 0; i < s.size(); i++){
        num += s[i] ^ t[i];
    }
    if(num == 0) return true;
    else return false;
}

int main(){
    auto t_start = chrono::high_resolution_clock::now();
    string s = "anagram", t = "nagaram";
    char a = 'a', b = 'a';
    int num = b^a;
    cout << num << endl;
    bool result = isAnagram(s, t);
    cout << result << endl;
    auto t_end = chrono::high_resolution_clock::now();
    cout << "Wall clock time passed: " << chrono::duration<double, milli>(t_end-t_start).count() << " ms\n";
    return 0;
}



