#include "solution.h"
#include<algorithm>

using namespace std;

vector<int> Solution::numMovesStonesII(vector<int> &stones)
{
    sort(stones.begin(), stones.end());
    int maxNum = stones[0];
    int minNum = stones[0];
    for (size_t i = 0; i < stones.size(); i++)
    {
        maxNum = stones[i] > maxNum ? stones[i] : maxNum;
        minNum = stones[i] < minNum ? stones[i] : minNum;
    }

    int numMoves1 = 0;
    int numMoves2 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    int maxPos = minNum + stones.size() - 1;
    int minPos = maxNum - stones.size() + 1;
    for (size_t i = 0; i < stones.size(); i++)
    {
        if (stones[i] <= maxPos) {
            cnt1++;
        }
        if (stones[i] >= minPos) {
            cnt2++;
        }
    }
    
    numMoves1 = stones.size() - cnt1;
    numMoves2 = stones.size() - cnt2;

    vector<int> res;
    res.push_back(min(numMoves1,numMoves2));
    res.push_back(max(numMoves1,numMoves2));

    return res;
}