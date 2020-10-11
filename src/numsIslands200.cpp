#include "solution.h"

using namespace std;

void dfs(pair<int, int> pos, vector<vector<char>> &grid, vector<vector<int>> &visited)
{
    int x = pos.first;
    int y = pos.second;
    visited[x][y] = 1;
    if (x+1 < grid.size() && grid[x+1][y] == '1' && visited[x+1][y] == 0) {
        dfs(make_pair(x+1,y), grid, visited);
    }
    if (x - 1 >= 0 && grid[x-1][y] == '1' && visited[x-1][y] == 0) {
        dfs(make_pair(x-1,y), grid, visited);
    }
    if (y+1 < grid[x].size() && grid[x][y+1] == '1' && visited[x][y+1] == 0) {
        dfs(make_pair(x,y+1), grid, visited);
    }
    if (y-1 >= 0 && grid[x][y-1] == '1' && visited[x][y-1] == 0) {
        dfs(make_pair(x,y-1), grid, visited);
    }
    return;
}

int Solution::numsIslands(vector<vector<char>> &grid)
{
    if (grid.empty()) {
        return 0;
    }
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> visited;
    for (size_t i = 0; i < rows; i++) {
        vector<int> tmp(cols,0);
        visited.push_back(tmp);
    }
    int nums = 0;
    // grid 可以看作是以邻接矩阵表示的图；用深度优先搜索找到相邻1的有几片；
    pair<int, int> pos;
    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1' && visited[i][j] == 0) {
                pair<int, int> pos = make_pair(i,j);
                nums++;
                dfs(pos, grid, visited);
            }
        }
    }
    return nums;
}