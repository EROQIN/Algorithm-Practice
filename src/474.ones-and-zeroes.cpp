/*
 * @lc app=leetcode.cn id=474 lang=cpp
 * @lcpr version=30204
 *
 * [474] 一和零
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

  int findMaxForm(vector<string> &strs, int m, int n) {
    //dp[i][j]:最多有i个0和j个1的str的最大子集的大小为dp[i][j]
    //确定递推公式：
    //dp[i][j]可以由前一个strs里的字符串推导出来，strs里的字符串zeroNum个0,oneNum个1
    //例：[10,00,11,0,1] m=3 , n=2
    /*
      0
    1 m:    0 1 2 3
    n    0  0 1 1 2
         1  1 2 2
         2
    */
    //从dp[1][1]这个点来看：与其有关联的点有dp[0][1],dp[1][0];
    //
    //

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(auto&& str: strs){
      int oneNum = 0,zeroNum=0;
      for(auto&& c:str){
        if(c=='0') ++zeroNum;
        else ++oneNum;
      }
      
      for(int i = m;i>=zeroNum;--i){
        for(int j = n;j>=oneNum;--j){
          dp[i][j] = max(dp[i][j],dp[i-zeroNum][j-oneNum]+1);
        }
      }
    }
    return dp[m][n];
    
  }
};
// @lc code=end

/*
// @lcpr case=start
// ["10", "0001", "111001", "1", "0"]\n5\n3\n
// @lcpr case=end

// @lcpr case=start
// ["10", "0", "1"]\n1\n1\n
// @lcpr case=end

 */
