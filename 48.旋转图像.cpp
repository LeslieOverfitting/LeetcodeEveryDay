#include<iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int up = 0;
        int down = matrix.size() -1;
        int left = 0;
        int right = matrix.size() - 1;
        while(left <= right && up <= down){
            int pos = 0;
            while(left + pos != right){
                int temp = matrix[up + pos][right];
                matrix[up + pos][right] = matrix[up][left + pos];
                matrix[up][left + pos] = matrix[down - pos][left];
                matrix[down - pos][left] = matrix[down][right - pos];
                matrix[down][right - pos] = temp;
                pos++;
                // for(int i = 0; i < matrix.size(); i++){
                //     for(int j = 0; j < matrix[i].size(); j++){
                //         cout<<matrix[i][j]<<" ";
                //     }
                //     cout<<endl;
                // }
            }
            up++;
            down--;
            left++;
            right--;
        }
    }
};
// @lc code=end

