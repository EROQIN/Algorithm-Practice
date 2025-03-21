/*
 * @lc app=leetcode.cn id=96 lang=cpp
 * @lcpr version=30204
 *
 * [96] 不同的二叉搜索树
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
    int numTrees(int n) {
        //0 1 2 5
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<n+1;++i){
            for(int j=1;j<=i;++j){
                dp[i] += dp[i-j]*dp[j-1];
            }
        }

        // for(auto& i : dp){
        //     cout << i << "  ";
        // }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

