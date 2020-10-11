#include <algorithm>
#include "solution.h"

using namespace std;

void dfs(pair<int, int> pos, vector<vector<int>> &grid, int &area)
{
    int x = pos.first;
    int y = pos.second;
    grid[x][y] = 0;
    area++;
    if (x+1 < grid.size() && grid[x+1][y] == 1) {
        dfs(make_pair(x+1,y), grid, area);
    }
    if (x - 1 >= 0 && grid[x-1][y] == 1) {
        dfs(make_pair(x-1,y), grid, area);
    }
    if (y+1 < grid[x].size() && grid[x][y+1] == 1) {
        dfs(make_pair(x,y+1), grid, area);
    }
    if (y-1 >= 0 && grid[x][y-1] == 1) {
        dfs(make_pair(x,y-1), grid, area);
    }
    return;
}
int Solution::maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty()) {
        return 0;
    }
    int rows = grid.size();
    int cols = grid[0].size();
    int maxArea = 0;
    // grid 可以看作是以邻接矩阵表示的图；用深度优先搜索找到相邻1的有几片；
    pair<int, int> pos;
    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1) {
                pair<int, int> pos = make_pair(i,j);
                int area = 0;
                dfs(pos, grid, area);
                maxArea = max(maxArea, area);
            }
        }
    }
    return maxArea;
}