/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int n;
    int m;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> mark(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mark[i][j] == 0 && grid[i][j] == 1){
                    ans = max(ans, dfs(grid, mark, i, j));
                }
            }
        }
        return ans;
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& mark, int x, int y){
        if(x < 0 || x >= n || y < 0 || y >= m || mark[x][y] == 1 || grid[x][y] == 0){
            return 0;
        }
        mark[x][y] = 1;
        return 1 + dfs(grid, mark, x + 1, y) + dfs(grid, mark, x - 1, y) + \
                dfs(grid, mark, x, y - 1) + dfs(grid, mark, x, y + 1);
    }
};
// @lc code=end

