/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30204
 *
 * [322] 零钱兑换
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
    int coinChange(vector<int>& coins, int amount) {
        //dp[i][j]下标含义：当前位置下，所能组合出的最少硬币个数
        //举例确定状态转移方程：
        //   0 1 2 3 4 5 6
        //1  1 1 2 3 4 5 6     //整除->赋值 相除结果
        //2  1 1 
        //5  1
        
        //if(coins[i] > j) dp[i][j] = dp[i-1][j];
        //if(coins[i] <= j) 1.不选coins[i] :dp[i][j] = dp[i-1][j]
        //                  2.选coins[i]  : dp[i][j] = dp[i][j-coins[i]] 
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

