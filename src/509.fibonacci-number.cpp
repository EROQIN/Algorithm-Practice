/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30204
 *
 * [509] 斐波那契数
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
    int fib(int n) {
        if(n==0) return 0;
        vector<int> res(n+2);
        //res[i] = res[i-1] + res[i-2]
        res[0] = 1,res[1] = 1;
        for(int i = 2;i<n;++i){
            res[i] = res[i-1] + res[i-2];
        }
        return res[n-1];  
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

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

