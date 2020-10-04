#include "solution.h"

using namespace std;

int Solution::findNumberOfLIS(vector<int>& nums)
{
    int len = nums.size();
    if (len == 0) {
        return 0;
    }
    vector<int> count(len,1);
    vector<int> dp(len,1);
    int maxLen = 1;
    for (size_t i = 1; i < len; i++) {
        for (size_t j = 0; j < i; j++) {
            if (nums[i] > nums[j])
            {
                if (dp[i] < dp[j] + 1)
                {
                    //nums[i]和nums[j]是一个递增子序列，且count[i]是由count[j]直接得到的，count是一样的
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[i] == dp[j] + 1)
                {
                    //nums[i]和nums[j]是一个递增子序列，但count[i]不是由count[j]直接得到的，这路nums[j]是另一条路；
                    count[i] += count[j];
                }
            }   
        }         
        maxLen = max(maxLen,dp[i]);
    }

    //找到最大递增子序列的个数
    int res = 0;
    for (size_t i = 0; i < len; i++) {
        if (dp[i] == maxLen) {
            res += count[i];
        }
    }
    return res;
}