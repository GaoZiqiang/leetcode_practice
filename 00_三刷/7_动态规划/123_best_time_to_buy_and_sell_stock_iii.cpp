/* leetcode T123:买卖股票的最佳时机III
 * 原题链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
 * */

/* 方法一：动态规划
 *
 * 方法二：动态规划
 * 算法思想：
 * 与T121和T122两题相比，本题最多完成两笔交易，注意是"最多"，那么就有了以下5种状态：
 * dp[i][0]：没有操作 不买也不卖
 * dp[i][1]：第一次持有股票-->(包括现在买入(前面不持有) 和 (前面买入)现在持有但未卖出两种情况)
 * dp[i][2]：第一次不持有股票-->(包括现在卖出(前面持有) 和 不持有(前面就不持有)两种情况)
 * dp[i][3]：第二次持有股票-->(包括现在买入(前面不持有) 和 (前面买入)现在持有但未卖出两种情况)
 * dp[i][4]：第二次不持有股票-->(包括现在卖出(前面持有) 和 不持有(前面就不持有)两种情况)
 *
 * 状态转移方程：
 * p[i][0] = dp[i-1][0];
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);// 第一次购买，在不持有股票的基础上-prices[i]
 * dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);//第一次卖出， 在第一次买入后的余额基础上+prices[i]
 * dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);// 第二次买入，在第一次卖出后的余额基础上-prices[i]
 * dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);// 第二次卖出，在第二次买入后的余额基础上+prices[i]
 *
 * 初始化：
 * dp[0][0] = dp[0][2] = dp[0][4] = 0;
 * dp[0][1] = dp[0][3] = -prices[0];
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O(5*n)。
 * */


#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    // n*5数组
    vector<vector<int>> dp(n, vector<int>(5));

    // 初始化
    dp[0][0] = dp[0][2] = dp[0][4] = 0;
    dp[0][1] = dp[0][3] = -prices[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0];// 继承上一次的不持有股票
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);// 第一次购买，在不持有股票的基础上-prices[i]
        dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);//第一次卖出， 在第一次买入后的余额基础上+prices[i]
        dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);// 第二次买入，在第一次卖出后的余额基础上-prices[i]
        dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);// 第二次卖出，在第二次买入后的余额基础上+prices[i]
    }

    return dp[n-1][4];
}