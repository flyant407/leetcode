#include<algorithm>
#include "solution.h"

using namespace std;

int Solution::lengthOfLIS(vector<int>& nums)
{
    int len = nums.size();
    if (len == 0) {
        return 0;
    }
    
    // dp[i]表示以nums[i]为结尾的最长上升子序列
    vector<int> dp(len,1);
    for (size_t i = 1; i < len; i++) {
        for (size_t j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i],dp[j] + 1);
            } else {
                continue;
            }
        }
    }
    sort(dp.begin(), dp.end());
    return dp[len-1];
}