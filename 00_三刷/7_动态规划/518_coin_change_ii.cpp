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
#include <vector>

using namespace std;

// 二维数组 k枚举
int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));// dp[i][j]:前i种面额，j总金额
    dp[0][0] = 1;
    for (int i = 1; i <= coins.size(); i++)
        for (int j = 0; j <= amount; j++)
            for (int k = 0; k <= j / coins[i - 1]; k++)
                dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
    return dp[coins.size()][amount];
}

// 一维数组 无枚举
int change(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<int> dp(amount+1, 0);

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        int coin = coins[i-1];
        for (int j = 0; j <= amount; j++) {
            if (j < coin) dp[j] = dp[j];
            else dp[j] = dp[j-coin] + dp[j];
        }
    }

    return dp[amount];
}

// 小优化
int change(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<int> dp(amount+1, 0);

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        int coin = coins[i-1];
        for (int j = coin; j <= amount; j++) {// j直接从coin开始
            dp[j] = dp[j-coin] + dp[j];
        }
    }

    return dp[amount];
}