/* leetcode T518:零钱兑换II
 * 原题链接：https://leetcode-cn.com/problems/coin-change-2/
 * */

/* 方法一：动态规划--类似于T343:整数拆分
 *
 * 算法思想：
 * dp[i][j]：使用前i种面额，实现j总金额的组合数
 *
 * 复杂度分析：
 * 时间复杂度：O(m*n*n)，m为amount，n为coins.size()。
 * 空间复杂度：O(m*n)，dp数组。
 * */

int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));// dp[i][j]:前i种面额，j总金额
    dp[0][0] = 1;
    for (int i = 1; i <= coins.size(); i++)
        for (int j = 0; j <= amount; j++)
            for (int k = 0; k <= j / coins[i - 1]; k++)
                dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
    return dp[coins.size()][amount];
}