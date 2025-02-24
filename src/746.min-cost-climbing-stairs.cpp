/*
 * @lc app=leetcode.cn id=746 lang=cpp
 * @lcpr version=30204
 *
 * [746] 使用最小花费爬楼梯
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
    int minCostClimbingStairs(vector<int>& cost) {
        //求走到当前位置i的最小花费
        //假设只有三格 3 2 1
        //动规数组：   3 2 3 2
        //状态转移方程： a[i] = min(a[i-1],a[i-2]);
        //求到达顶部，假设楼梯有5阶，结果应当是a[4]。
        //更一般地，结果返回值为a[cost.size()-1];
        //分析结束
        if(cost.size()<2) return 0;
        // vector<int> cost2 = cost;
        //疏漏1：顶部实际位置为size+1的楼梯
        vector<int> a(cost.size()+1);
        a[0] = cost[0];
        a[1] = cost[1];
        cout << a[0] << "   " << a[1] << "   ";
        for(int i = 2;i<cost.size();++i){
            //疏漏2：这里需要加上cost
            a[i] = min(a[i-1],a[i-2]) + cost[i];
            cout << a[i] << "   ";
        }
        a[cost.size()] = min(a[cost.size()-1],a[cost.size()-2]);
        return a[cost.size()];





        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,15,20]\n
// @lcpr case=end

// @lcpr case=start
// [1,100,1,1,1,100,1,1,100,1]\n
// @lcpr case=end

 */

