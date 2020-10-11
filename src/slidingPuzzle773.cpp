#include <string>
#include <queue>
#include "solution.h"

using namespace std;

string Solution::getNextStatus(string status, int move)
{
    string newStatus = status;
    int zeroPos = status.find("0");
    switch (move) {
        case 0://up
        if (zeroPos/3 == 1) {
            newStatus[3+zeroPos%3] = status[zeroPos%3];
            newStatus[zeroPos%3] = status[3+zeroPos%3];
        } else {
            newStatus = "";
        }
        break;
        case 1://down
        if (zeroPos/3 == 0) {
            newStatus[3+zeroPos%3] = status[zeroPos%3];
            newStatus[zeroPos%3] = status[3+zeroPos%3];
        } else {
            newStatus = "";
        }
        break;
        case 2://left
        if (zeroPos%3 > 0) {
            if (zeroPos/3 == 0) {
                newStatus[zeroPos] = status[zeroPos-1];
                newStatus[zeroPos-1] = status[zeroPos];
            }
        } else {
            newStatus = "";
        }
        break;
        case 3://right
        if (zeroPos%3 < 2) {
            if (zeroPos/3 == 0) {
                newStatus[zeroPos] = status[zeroPos+1];
                newStatus[zeroPos+1] = status[zeroPos];
            } 
        } else {
            newStatus = "";
        }
        break;
        default:
        newStatus = "";
        break;
    }
    return newStatus;
}

string vectorInt2Str(vector<vector<int>>& board)
{
    string str;
    for (auto vec : board) {
        for (auto val : vec) {
            str += to_string(val);
        }
    }
    return str;
}

int Solution::slidingPuzzle(vector<vector<int>>& board)
{
    string goal = "123450";
    queue<string> statusQ;
    int steps = 0;
    string currentStr = vectorInt2Str(board);

    if (currentStr == goal) {
        return steps;
    }
    statusQ.push(currentStr);

    while (!statusQ.empty()) {
        currentStr = statusQ.front();
        statusQ.pop();
        if (currentStr == goal) {
            return steps;
        }

        for (int i = 0; i < 4; i++) {
            string nextStatus = getNextStatus(currentStr,i);
            if (nextStatus !="") {
                statusQ.push(nextStatus);
                steps++;
            }
        }
    }
    return -1;
}