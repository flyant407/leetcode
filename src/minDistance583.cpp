#include "solution.h"
#include <algorithm>

using namespace std;

int lcs(string &str1, string &str2) 
{
    int len1 = str1.size() + 1;
    int len2 = str2.size() + 2;
    int dp[len1][len2];
    for (size_t i = 0; i < len1; i++) {
        dp[i][0] = 0;
    }
    for (size_t j = 0; j < len2; j++) {
        dp[0][j] = 0;
    } 

    for (size_t i = 1; i < len1; i++) {
        for (size_t j = 1; j < len2; j++) {
            if (str1[i-1] == str2 [j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[len1-1][len2-1];
}

int Solution::minDistance(string word1, string word2)
{
    int res = 0;
    int lcsLen = lcs(word1, word2);
    res = word1.size() + word2.size() - 2 * lcsLen;
    return res;
}