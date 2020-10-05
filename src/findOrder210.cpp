#include <queue>
#include "solution.h"

using namespace std;

vector<int> Solution::findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> res;
    vector<int> indegree(numCourses,0);
    vector<vector<int>> adjacency(numCourses);

    for (auto item : prerequisites)
    {
        indegree[item[0]]++;
        adjacency[item[1]].push_back(item[0]);
    }

    queue<int> zeroDegree;
    for (size_t i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            zeroDegree.push(i);
        }
    }

    while (!zeroDegree.empty())
    {
        int course = zeroDegree.front();
        zeroDegree.pop();
        res.push_back(course);
        for (auto item : adjacency[course])
        {
            indegree[item]--;
            if (indegree[item] == 0)
            {
                zeroDegree.push(item);
            }
        }
    }
    if (res.size() == numCourses)
    {
        return res;
    } else {
        return {};
    }
    
    
    
}