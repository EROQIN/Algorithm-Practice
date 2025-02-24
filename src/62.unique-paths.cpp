/*
 * @lc app=leetcode.cn id=62 lang=cpp
 * @lcpr version=30204
 *
 * [62] 不同路径
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
    int uniquePaths(int m, int n) {
        //下标含义：从start开始走到该处的所有不同路径
        //图长度为m*n
        //1 1 1 1 1
        //1 2 3 4 5
        //每一个点位可以由它上方和左方的点位进入
        //所以状态转移方程：
        //dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //注意边界检测
        vector<vector<int>> dp(m,vector<int>(n));
        //dp[m][n]
        //初始化：
        for(int i = 0;i<m;++i){
            dp[i][0] = 1;
        }
        for(int j = 0;j<n;++j){
            dp[0][j] = 1;
        }
        for(int i = 1; i<m; ++i){
            for(int j = 1;j<n;++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

    }
    
    
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */

