/* leetcode T322:零钱兑换
 * 原题链接：https://leetcode-cn.com/problems/coin-change/
 * */

/* 方法一：动态规划--类似于T343:整数拆分
 *
 * 算法思想：
 * 以下面这个例子为例：
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3
 * 解释：11 = 5 + 5 + 1
 * 假设x总金额共dp[x]中组合
 * d[11] = min(dp[11-1]+1, dp[11-2]+1, dp[11-5]+1) = min(dp[11-1], dp[11-2], dp[11-5]) + 1
 * 以此类推：dp[i] = min(dp[i-coins[0]], dp[i-coins[1]], ... dp[i-coins[m]]) + 1
 * 由此确定dp的要素：
 *
 * 1 dp数组 dp[i]表示总金额为i时的组合总数
 * 2 dp初始化 dp[0] = 0,另外当金额总数小于面额coins[j]时，取dp[i-coins[j]]为无穷大
 * 3 状态转移方程 dp[i] = min(dp[i - coins[j]], dp[i]); j = [0, coins.size()-1]
 * 4 遍历顺序 [0, amount]
 *
 * 复杂度分析：
 * 时间复杂度：O(m*n)，m为amount，n为coins.size()。
 * 空间复杂度：O(n)，dp数组。
 * */

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();

    vector<int> dp(amount+1, amount+1);// 默认值取为最大，d[i]理论上不会超过总金额amount的大小(考虑amount为0)

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int coin = coins[i-1];
        for (int j = coin; j <= amount; j++) {
            dp[j] = min(dp[j], dp[j-coin] + 1);
        }
    }

    return dp[amount] == amount+1 ? -1 : dp[amount];
}

// k枚举-->超时
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();

    vector<int> dp(amount+1, 0x3f3f3f3f);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int coin = coins[i-1];
        for (int j = amount; j >= coin; j--) {
            for (int k = 0; k * coin <= j; k++) {// 使用k枚举-->超时
                dp[j] = min(dp[j], dp[j-k*coin] + k);
            }
        }
    }

    return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
}