/*
 * @lc app=leetcode.cn id=63 lang=cpp
 * @lcpr version=30204
 *
 * [63] 不同路径 II
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        auto dp = obstacleGrid;
        //dp初始化：
        for(auto& i : dp){
            for(auto& j : i){
                j = j ? 0 : 1;
            }
        }
      
        for (int i = 0,n=1; i<obstacleGrid.size();++i) {
            if(dp[i][0] == 0){
                n=0;
            }
            dp[i][0] = n;
        }
        for (int i = 0,n=1; i<obstacleGrid[0].size();++i) {
            if(dp[0][i] == 0){
                n=0;
            }
            dp[0][i] = n;
        }
        
        //状态转移方程：dp[i][j] = dp[i-1][j] + dp[i][j-1];

        for(int i = 1;i<dp.size();++i){
            for(int j = 1;j<dp[i].size();++j){
                if(dp[i][j]==0) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

 */

