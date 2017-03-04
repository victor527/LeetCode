/*#include <iostream>
#include <string>
#include "RepeatedSubstringPattern.h"

using namespace std;

int main()
{
    string str = "abcababc";
    bool indicator;
    indicator = repeatedSubstringPattern(str);
    cout << indicator << endl;
    cout << 3 / 3 * 3 + 1 / 3 << endl;
    return 0;
}*/


// make_pair example
#include <utility>      // std::pair
#include <iostream>     // std::cout
#include <unordered_map>
#include <vector>

using namespace std;

int main () {
  pair <int,int> foo;
  pair <int,int> bar;
  pair <int,char> haa;

  haa = std::make_pair (1, 66);
 
  foo = std::make_pair (10,20);
  bar = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>
 
  std::cout << "haa: " << haa.first << ", " << haa.second << '\n';
  std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

  std::string p = "ABCD";
  std::unordered_map<char, int> map1,hash;
  for(int i = 0; i < p.size(); i++){
  	map1[p[i]]++;
  }
  hash = map1;

  std::cout <<"map1: " << map1[65] << std::endl;
  std::cout <<"hash: " << hash[65] << std::endl;

  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(1);
  int k = 5;
  unordered_map<int, int> map;
  cout << nums[2] << endl;
  for(int i = 0; i < nums.size(); i++)
  {
  	if(map.find(nums[i]) != map.end() && i - map[nums[i]] <= k)
  		cout << "true" << endl;
  	map[nums[i]] = i;
  }
  cout << "false" << endl;
 
  return 0;
}