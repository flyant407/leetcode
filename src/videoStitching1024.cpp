#include "solution.h"

using namespace std;

bool GetLongestPart(int &start, int &end, vector<vector<int> >& clips)
{
    int maxLen = 0;
    int newStart = start;
    int newEnd = end;
    for (auto &item : clips) {
        if ( item[0] >= start && item[0] <= end && item[1] > end ) {
            int len = item[1] - end;
            if (maxLen < len) {
                maxLen = len;
                newStart = item[0];
                newEnd = item[1];
            }
        }
    }
    if (maxLen == 0) {
        return false;
    } else {
        start = newStart;
        end = newEnd;
        return true;
    }
}

int Solution::videoStitching(vector<vector<int> >& clips, int T)
{
    if (T == 0) {
            return 0;
        }

        int start = 0;
        int end = 0;
        int num = 0;
        while (end < T) {
            if (!GetLongestPart(start,end, clips)) {
                return -1;
            } else {
                num++;
            }
        }
        return num;
}