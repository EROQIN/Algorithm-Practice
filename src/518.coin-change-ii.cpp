// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=518 lang=cpp
 * @lcpr version=30204
 *
 * [518] 零钱兑换 II
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
  void print(vector<vector<int>> &dp) {
    for (auto &&i : dp) {
      for (auto &&j : i) {
        cout << j << " ";
      }
      cout << endl;
    }
  }

  int change(int amount, vector<int> &coins) {
    // dp[i][j]
    //下标含义：当前amount下，使用i前硬币所能凑成金额的方式
    /*
    coins : 1 2 5
amount    0 0 0 0
          1 1 1 1
          2 1 2 2
          3 1 2 2
          4 1 3 3
          5 1 3 4
    */
    // if(coin > amount) dp[i][j] = dp[i][j-1];
    // if(coin == amount) dp[i][j] = dp[i][j-1]+1;
    // 分为：需要coin + 不要coin；
    //不要coin时，方法数是：dp[i][j-1]
    //要coin时， 方法数是： dp[i-coin][j]
    // if(coin < amount) dp[i][j] = dp[i][j-1] + dp[i-coin][j];

    //创建dp数组：
    vector<vector<unsigned long long int>> dp(
        amount + 1, vector<unsigned long long int>(coins.size(), 0));
    // dp[amount][count]
    //初始化 init
    for (int i = 1; i < dp.size(); ++i) {
      if (i % coins[0] == 0)
        dp[i][0] = 1;
      else
        dp[i][0] = 0;
    }
    for (int i = 0; i < dp[0].size(); ++i) {
      dp[0][i] = 1;
    }
    // print(dp);

    //遍历dp数组
    for (int i = 1; i < dp.size(); ++i) {      // amount
      for (int j = 1; j < dp[i].size(); ++j) { // coins
        if (coins[j] > i)
          dp[i][j] = dp[i][j - 1];
        else if (coins[j] == i)
          dp[i][j] = dp[i][j - 1] + 1;
        else
          dp[i][j] = dp[i][j - 1] + dp[i - coins[j]][j];
      }
    }
    // print(dp);

    return dp[amount][coins.size() - 1];
  }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n[1, 2, 5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[10]\n
// @lcpr case=end

 */
