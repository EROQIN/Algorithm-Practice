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
        backtracking(nums, target, 0);
        return result;
        


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

