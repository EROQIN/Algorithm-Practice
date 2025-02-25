/*
 * @lc app=leetcode.cn id=343 lang=cpp
 * @lcpr version=30204
 *
 * [343] 整数拆分
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
    int integerBreak(int n) {
        //dp下标代表分解一个数字，所能得到的最大乘积
        //n=6时
        //   0 1 2 3 4 5 6
        //dp 0 0 1 2 4 6 9
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        // cout << dp[0] << "   " << dp[1] << "   " << dp[2] << "   ";
        //dp[i] = max(dp[i],max((i-j)*j,dp[i-j]*j))
        for(int i = 3;i<n+1;++i){
            for(int j = 1;j<i;++j){
                dp[i] = max(dp[i],max((i-j)*j,dp[i-j]*j)); 
            }
            // cout << dp[i] << "    ";
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

