/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 * @lcpr version=30204
 *
 * [1049] 最后一块石头的重量 II
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // int sum = accumulate(stones.begin(),stones.end(),0);
        // vector<int> dp(15001,0);
        // int target = sum/2;
        // for(int i=0;i<stones.size();++i){
        //     for(int j = target;j>=stones[i];--j){
        //         dp[j] = max(dp[j],dp[j-stones[i]]+stones[i]);
        //     }
        // }    
        // return sum-dp[target]-dp[target];
        int sum = accumulate(stones.begin(),stones.end(),0);
        vector<int> dp(15001,0);
        int target = sum/2;
        for(int i=0;i<stones.size();++i){
            for(int j = target;j>=stones[i];--j){
                dp[j] = max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }
        return (sum - dp[target]) - dp[target];
        

    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,4,1,8,1]\n
// @lcpr case=end

// @lcpr case=start
// [31,26,33,21,40]\n
// @lcpr case=end

 */

