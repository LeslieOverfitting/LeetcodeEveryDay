#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int n;
    int m;
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> mark(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mark[i][j] == 1 || grid[i][j] == '0')
                    continue;
                dfs(grid, mark, i, j);
                ans++;
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& mark, int x, int y){
        if(x<0||y<0||x>=n||y>=m||grid[x][y] == '0' || mark[x][y] == 1)
            return;
        mark[x][y] = 1;
        dfs(grid, mark, x + 1, y);
        dfs(grid, mark, x - 1, y);
        dfs(grid, mark, x, y - 1);
        dfs(grid, mark, x, y + 1);
    }
};
// @lc code=end

