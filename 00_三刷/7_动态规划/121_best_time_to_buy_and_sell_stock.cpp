/* leetcode T121:买卖股票的最佳时机
 * 原题链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 * */

/* 方法一：一次遍历(贪心算法)
 *
 * 算法思想：
 *
 * 关键点：
 * 使用minPrice记录之前的最小价格
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，一次遍历。
 * 空间复杂度：O(1)。
 *
 * 方法二：动态规划
 * 算法思想：
 * 两种状态：
 * dp[i][0]：持有股票(包括现在买入(前面不持有) 和 (前面买入)现在持有但未卖出两种情况)
 * dp[i][1]：不持有股票(包括现在卖出(前面持有) 和 不持有(前面就不持有)两种情况)
 * 状态转移方程：
 * dp[i][0] = max(dp[i-1][0], -prices[i]);
 * dp[i][1] = max(dp[i-1][1], prices[i]+dp[i-1][0]);
 * 初始化：
 * dp[i][0] = -prices[0];
 * dp[i][1] = 0;
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O(2*n)。
 * */

#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = prices[0], res = -1;

    for (int i = 1 ; i < prices.size(); i++) {
        if (prices[i] > minPrice) {
            res = max(res, prices[i] - minPrice);// 当前价格减去之前的最小价格
        }
        minPrice = min(minPrice, prices[i]);// 更新目前为止的最小价格
    }

    return res == -1 ? 0 : res;
}

// 解法二：动态规划
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(2));

    dp[0][0] -= prices[0];// 持有
    dp[0][1] = 0;// 不持有

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], -prices[i]);// 买入时余额为0(因为只买一次)
        dp[i][1] = max(dp[i-1][1], prices[i]+dp[i-1][0]);
    }

    return dp[n-1][1];
}