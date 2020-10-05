#ifndef _SOLUTION_H
#define _SOLUTION_H

#ifndef HELLO_MSG
#define HELLO_MSG "hello in header"
#endif
#include <iostream>
#include <vector>
#include <queue>

int hello();
void foo();

class Solution {
public:
    static bool cmp(std::pair<int,int> &a, std::pair<int, int> &b);
    std::vector<int> topKFrequent(std::vector<int>& nums, int k);
    int videoStitching(std::vector<std::vector<int> >& clips, int T);
    bool CanVisitAllRooms(std::vector<std::vector<int>>& rooms);
    int longestCommonSubsequence(std::string text1, std::string stext2);
    int minDistance(std::string word1, std::string word2);
    int countSubstrings(std::string s);
    std::vector<int> numMovesStonesII(std::vector<int> &stones);
    int lengthOfLIS(std::vector<int>& nums);
    int findNumberOfLIS(std::vector<int>& nums);
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped);
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites);
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites);

private:
    bool isPlalindrome(std::string s);
};

#endif

