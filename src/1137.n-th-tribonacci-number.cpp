/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 * @lcpr version=30204
 *
 * [1137] 第 N 个泰波那契数
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
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        vector<int> T(n+3);
        T[0] = 0;
        T[1] = 1;
        T[2] = 1;
        for(int i=3;i<=n;++i){
            T[i] = T[i-1]+T[i-2]+T[i-3];
            // cout << T[i] << "   ";
        }
        return T[n];
    }
};
// int main(){
//     Solution solution;
//     solution.tribonacci(4);
// }
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 25\n
// @lcpr case=end

 */

