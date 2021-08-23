#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start

class Solution { // 38min
public:
    int action_x[4] = {1, -1, 0, 0 };
    int action_y[4] = {0, 0,  1, -1 };
    int b_n = 0;
    int b_m = 0;
    void solve(vector<vector<char>>& board) {
        b_n = board.size();
        b_m = board[0].size();
        for(int i = 0; i < b_n; i++){
            dfs(board, i, 0);
            dfs(board, i, b_m - 1);
        }

        for(int i = 0; i < b_m; i++){
            dfs(board, 0, i);
            dfs(board, b_n - 1, i);
        }
        for(int i = 0; i < b_n; i++){
            for(int j = 0; j < b_m; j++){
                if(board[i][j] == 'A')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y){
        if(x < 0 || y < 0 || x >= b_n || y >= b_m)
            return;
        if(board[x][y] == 'X')
            return;
        if(board[x][y] == 'A')
            return;
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    // void solve(vector<vector<char>>& board) {
    //     b_n = board.size();
    //     b_m = board[0].size();
    //     vector<vector<int>> mark(b_n, vector<int>(b_m, 0));
    //     for(int i = 0; i < b_n; i++){
    //         for(int j = 0; j < b_m; j++){
    //             if(board[i][j] == 'X' || mark[i][j] == 1)
    //                 continue;
    //             mark[i][j] = 1;
    //             vector<pair<int, int>> p;
    //             p.push_back(pair<int, int>(i, j));
    //             if(dfs(board, mark, p, i, j ) == false){
    //                 //cout<<" x"<<i<<" y"<<j<<endl;
    //                 for(auto x: p){
    //                     board[x.first][x.second] = 'X';
    //                 }
    //             }
    //         }
    //     }
    // }

    // bool dfs(vector<vector<char>>& board, vector<vector<int>>& mark, vector<pair<int, int>>& p, int x, int y){
    //     bool flag = false;
    //     for(int i = 0; i < 4; i++){
    //         int new_x = x + action_x[i];
    //         int new_y = y + action_y[i];
    //         if(new_x < 0 || new_y < 0 || new_x >= b_n || new_y >= b_m){
    //             flag = true;
    //             continue;
    //         }
    //         if(mark[new_x][new_y] == 1){
    //             continue;
    //         }
    //         if(board[new_x][new_y] == 'O'){
    //             p.push_back(pair<int, int>(new_x, new_y));
    //             mark[new_x][new_y] = 1;
    //             if(dfs(board, mark, p, new_x, new_y)){
    //                 flag = true;
    //             }
    //         }
    //     }
    //     return flag;
    // }

};
// @lc code=end

