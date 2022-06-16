/* leetcode T188:买卖股票的最佳时机IV
 * 原题链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
 * */

/* 方法一：
 *
 * 方法二：动态规划
 * 算法思想：
 * 与T123:买卖股票的最佳时机III同一算法思想，只是这里有2*k+1中状态：
 *
 * dp[i][0]：没有操作 不买也不卖
 * j为奇数时：
 * dp[i][j]：第j次持有股票-->(包括现在买入(前面不持有) 和 (前面买入)现在持有但未卖出两种情况)
 * j为偶数时：
 * dp[i][j]：第j次不持有股票-->(包括现在卖出(前面持有) 和 不持有(前面就不持有)两种情况)
 *
 * 状态转移方程：
 * p[i][0] = dp[i-1][0];
 * dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]);// 第j次购买，在不持有股票的基础上-prices[i]
 * dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + prices[i]);//第j次卖出， 在第一次买入后的余额基础上+prices[i]
 *
 * 初始化：
 * for (int i = 0; i < 2*k+1; i++) {
 *  if (i %2 == 0) dp[0][i] = 0;
 *    else dp[0][i] = -prices[0];
 * }
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O((2*k+1)*n)。
 * */

#include <vector>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0 || k == 0) return 0;

    vector<vector<int>> dp(n, vector<int>(2*k+1));

    // 初始化
    for (int i = 0; i < 2*k+1; i++) {
        if (i %2 == 0) dp[0][i] = 0;
        else dp[0][i] = -prices[0];
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0];
        for (int j = 1; j < 2*k+1; j++) {
            if (j %2 == 1) dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]-prices[i]);// 持有股票
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+prices[i]);// 不持有
        }
    }

    return dp[n-1][2*k];
}