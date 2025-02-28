/*
 * @lc app=leetcode.cn id=494 lang=cpp
 * @lcpr version=30204
 *
 * [494] 目标和
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
#include <math.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:

    int sum = 0;
    vector<int> path;
    int result = 0;
    void backtracking(vector<int>& nums, int& target, int x){
        if(x == nums.size() && sum == target){
            ++result;
            return;
        }
        if(x >= nums.size()) return;
        
        sum += nums[x];
        ++x;
        backtracking(nums, target, x);
        --x;
        sum -= nums[x];

        sum -= nums[x];
        ++x;
        backtracking(nums, target, x);
        --x;
        sum += nums[x];

    }



    int findTargetSumWays(vector<int>& nums, int target) {
        //把所有数字分成两部分，一个部分是正，一个部分是负；
        //每个数字只能使用一次，且必须被使用
        //求所有和为target的方法种类数

        //回溯尝试：
        // backtracking(nums, target, 0);
        // return result;
        //回溯法AC，耗时1513ms
        
        //下面开始动态规划：
        
        //假设加法的总和为x，那么减法对应的总和就是sum - x。
        //x - (sum-x) = target
        //x = (target + sum)/2
        //此时问题就转化为用nums装满容量为x的背包，有几种方法。
        //这里是x，就是背包容量
        //先用二维dp数组解决这个问题：
        //dp[i][j]:使用下标为[0,i]的nums[i]能够凑满j这么大容量的背包，有dp[i][j]种方法。

        //确定递推公式：
        //现手动推导，画图，自己填表：
        /**
          
        背包容量： 0 1 2 3 4
        物品0:    1 1 0 0 0
        物品1:    1 2 1 0 0
        物品2:    1 3 3 1 0
        物品3:    1 4 
        物品4:    1 5
        * */
        //考虑dp[2][2]这个点，对于01背包的每一点，应当从该点的状态出发，例如：
        //dp[2][2]这个点，物品2有两种状态，"有"和"无"，所以我们分两种情况来讨论：
        //1.不选物品2的情况：
        //此时的方法数，正好就是物品0、1的方法数，在图中就是dp[1][2]。
        //2.选择物品2的情况：
        //此时，我们要考虑的就是，先装物品2本身，然后看背包的剩余空间，剩余空间由物品0、1填满
        //本题要求的是总方法数，状态转移方程的形式应该是：dp[i][j] = 不选择物品i的情况数 + 选择物品i的情况数 
        //那么，我们得到的状态转移方程就是：
        //dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
        //如果装不下物品i，则是dp[i][j] = dp[i-1][j]
        int sum = accumulate(nums.begin(),nums.end(),0);
         if((target + sum)%2 == 1){
            return 0; //此时无解
        }
        if(abs(target) > sum) return 0;
        // 加法总和
        int bagSize = (target+sum)/2;
        vector<vector<int>> dp(nums.size(),vector<int>(bagSize + 1,0));
        //初始化第一行：
        if(nums[0] <= bagSize) dp[0][nums[0]] = 1;
        // 初始化最左列：
        dp[0][0] = 1;
        int numsZero = 0;
        for(int i = 0;i<nums.size();++i){
            if(nums[i] == 0) ++numsZero;
            dp[i][0] = (int) pow(2.0,numsZero);
        }
        for (int i = 1; i< nums.size(); ++i) {
            for (int j = 1; j<=bagSize; ++j) {
                if(nums[i] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
            }
        }
        return dp[nums.size() - 1][bagSize];



    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

