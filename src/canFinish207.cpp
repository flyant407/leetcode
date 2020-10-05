#include "solution.h"
#include <map>

using namespace std;

//拓扑排序
bool Solution::canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> indegree(numCourses,0);
    map<int,vector<int>> adjacency;

    for (auto pair : prerequisites) {
        indegree[pair[0]]++;
        adjacency[pair[1]].push_back(pair[0]);
    }

    vector<int> visited(numCourses,0);
    int passCnt = 0;
    while (passCnt <= numCourses) {
        bool find = false;
        for (size_t i = 0; i < indegree.size(); i++) {
            if (visited[i] == 0 && indegree[i] == 0) {
                visited[i] = 1;
                passCnt++;
                find = true;
                if (adjacency.count(i)) {
                    for (auto course : adjacency[i]) {
                        indegree[course]--;
                    }
                }
                
            }
        }
        if (find == false)
        {
            break;
        }
    }

    if (passCnt == numCourses)
    {
        return true;
    } else {
        return false;
    }
}