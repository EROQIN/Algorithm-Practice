/*
 * @lc app=leetcode.cn id=198 lang=cpp
 * @lcpr version=30204
 *
 * [198] 打家劫舍
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
    int rob(vector<int>& nums) {
        // 1 2 3 1
        // 4
        // 下标的含义：最终走到此处时，最大的盗窃量
        // a[i] = max(a[i-2],a[i-3])+nums[i]
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }
        //在数组大小大于等于3时：
        vector<int> a(nums.size());
        a[0] = nums[0];
        a[1] = nums[1];
        a[2] = a[0] + nums[2];
        // cout << a[0] << "   " <<a[1]<< "   " << a[2] << "   ";
        for(int i = 3;i<a.size();++i){
            a[i] = max(a[i-2],a[i-3])+nums[i];
            // cout << a[i] << "   ";
        }
        return max(a[a.size()-1],a[a.size()-2]);



    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */

