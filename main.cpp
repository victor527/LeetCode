#include <iostream>
#include <string>
#include "RepeatedSubstringPattern.h"

using namespace std;

int main()
{
    string str = "abcabcabc";
    bool indicator;
    indicator = repeatedSubstringPattern(str);
    cout << indicator << endl;
    return 0;
}
