/* leetcode T122:买卖股票的最佳时机 II
 * 原题链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 * */

#include <vector>
#include <stdio.h>

/* 方法一：贪心算法+一阶差分
 *
 * 算法思想：
 * 贪心算法--从小处着手(局部最优)--有利可图就上--只要有大于last的架构就卖出
 * 每一个买入的价格last，只要后边遇到大于last的价格，就考虑卖出
 * 遇到小于last的价格，就更新买入价格
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，一次遍历。
 * 空间复杂度：O(1)，不需要额外空间。
 *
 * 方法二：动态规划
 *
 * 算法思想：参考https://www.programmercarl.com/0122.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAII%EF%BC%88%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%EF%BC%89.html#%E6%80%9D%E8%B7%AF
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，一次遍历。
 * 空间复杂度：O(n*2)，dp数组。
 * */

using namespace std;

// 解法一：贪心算法
int maxProfit(vector<int>& prices) {
    int res = 0;
    int pre = INT_MAX;

    for (auto& price : prices) {
        if (price > pre) {
            res += price - pre;
        }
        pre = price;
    }

    return res;
}

// 我的解法
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int res = 0;
    int last = prices[0];

    for (int i = 1; i < n; i++) {
        // 遇到小于last price的就更新last--(更新)买入价格
        if (prices[i] < last) last = prices[i];
        // 只要大于last price就考虑卖出
        if (prices[i] > last) {
            res += prices[i] - last;
            last = prices[i];
        }
    }

    return res;
}

// 动态规划
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));

    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < n; i++) {
        // 持有股票(包括买入股票)
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);// 买入时余额可能不是0
        // 不持有股票(包括卖出股票)
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
    }

    return dp[n-1][1];
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int profit = maxProfit(prices);
    printf("profit: %d\n",profit);
}