#include <stack>
#include <map>
#include "solution.h"

using namespace std;

bool Solution::isValid(std::string s)
{
    stack<char> myStack;
    if (s.empty() || s.size()%2 != 0) {
        return false;
    }
    int visited = 0;
    for (visited = 0; visited < s.size(); visited++) {
        myStack.push(s[visited]);
        while ((!myStack.empty()) && (myStack.top() == ')' || myStack.top() == '}' || myStack.top() == ']')) { // 这里每一个左符号只可能与一个右符号配对，不可能有出现while希望的多次情况；
            char current = myStack.top();
            myStack.pop();
            if (myStack.empty()) {
                return false;
            }
            if (current == ')' && myStack.top() != '(') {
                return false;
            }
            if (current == '}' && myStack.top() != '{') {
                return false;
            }
            if (current == ']' && myStack.top() != '[') {
                return false;
            }
            myStack.pop();
        }
    }

    if (visited == s.size() && myStack.empty()) {
        return true;
    }
    return false;
}
/*
* 上面算法的实现过程中，由于括号的种类很多，判断起来复杂，可以使用hash表来简化实现
*/

bool Solution::isValideOpt(string s)
{
    if (s.empty() || s.size() % 2 == 1) {
        return false;
    }
    map<char, char> validePairs = {
        {')','('},
        {']','['},
        {'}','{'},
    };
    stack<char> stk;
    for (char c : s) {
        if (validePairs.count(c)) {
            if (stk.empty() || stk.top() != validePairs[c]) {
                return false;
            } else {
                stk.pop();
            }
        } else {
            stk.push(c);
        }
    }
    if (stk.empty()) {
        return true;
    } else {
        return false;
    }
}
