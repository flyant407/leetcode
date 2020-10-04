#include "solution.h"

using namespace std;

bool Solution::isPlalindrome(string s)
{
    int len = s.size();
    for (size_t i = 0; i < len/2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int Solution::countSubstrings(string s)
{
    int nums = 0;
    for (size_t start = 0; start < s.size(); start++) {
        int left = start;
        for (size_t len = 1; len <= s.size() - left; len++) {
            string tmp = s.substr(left,len);
            if (isPlalindrome(tmp)) {
                nums++;
            }
        }
    }

    return nums;
}