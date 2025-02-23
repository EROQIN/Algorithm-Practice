/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30204
 *
 * [70] 爬楼梯
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
    int climbStairs(int n) {
        //a[i] = a[i-1] + a[i-2]
        if(n == 1) return 1;
        vector<int> vec(n+1);
        vec[0] = 1;
        vec[1] = 1;
        for(int i = 2;i<n+1;++i){
            vec[i] = vec[i-1] + vec[i-2];
        }
        return vec[n];
    
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

