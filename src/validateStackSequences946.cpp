#include <stack>
#include <queue>
#include "solution.h"

using namespace std;

bool Solution::validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
    int pushedLen = pushed.size();
    int poppedLen = popped.size();
    if (pushedLen != poppedLen)
    {
        return false;
    }
    if (pushedLen == 0)
    {
        return true;
    }

    stack<int> pushedStack;
    int current = 0;
    int pushedIndex = 0;
    pushedStack.push(pushed[pushedIndex++]);
    while (!pushedStack.empty())
    {
        while (!pushedStack.empty() && current < poppedLen && pushedStack.top() == popped[current])
        {
            pushedStack.pop();
            current++;
        }
        if (pushedIndex < pushedLen)
        {
            pushedStack.push(pushed[pushedIndex++]);
        } else if (pushedIndex == pushedLen && !pushedStack.empty() && pushedStack.top() != popped[current])
        {
            break;
        }
    }
    
    
    if (current == poppedLen)
    {
        return true;
    }

    return false;
}


