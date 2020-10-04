#include "solution.h"
#include <map>
#include <queue>

using namespace std;

bool Solution::cmp(std::pair<int,int> &a, std::pair<int, int> &b)
{
        return a.second > b.second;
}

vector<int> Solution::topKFrequent(std::vector<int>& nums, int k)
{
    vector<int> res;
    if (nums.size() == k) {
        return nums;
    } else if (nums.size() == 1 && k == 0) {
        return res;
    }

    map<int, int> valCnt;
    for (auto &val : nums) {
        valCnt[val]++;
    }

    priority_queue<pair<int,int>, vector<pair<int,int> >, decltype(&cmp)> q(cmp);

    for (auto &item : valCnt) {
        if (q.size() == k) {
            if (q.top().second < item.second) {
                q.pop();
                q.push(item);
            } 
        } else {
            q.push(item);
        }
    }

    while (!q.empty()) {
        res.push_back(q.top().first);
        q.pop();
    }
    
    return res;

}