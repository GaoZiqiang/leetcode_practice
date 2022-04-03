/* leetcode T322:零钱兑换
 * 原题链接：https://leetcode-cn.com/problems/coin-change/
 * */

/* 方法一：动态规划--完全背包问题
 *
 * 时间复杂度：O(n*amount)：。
 * 空间复杂度：O(n*amount)：二维数组。
 * */

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount+1,  0x3f3f3f3f);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = coins[i-1]; j <= amount; j++) {
            dp[j] = min(dp[j], dp[j-coins[i-1]] + 1);
        }
    }

    return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
}