/* leetcode T746:使用最小花费爬楼梯
 * 原题链接：https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 * */

/* 方法一：动态规划
 *
 * 算法思想：
 * 1 dp数组：dp[i]爬到第i个台阶时所需要的花费
 * 2 递推公式：dp[i] = min(dp[i-2] + cost[i], dp[i-1] + cost[i]);
 * 3 dp初始化：dp[0] = cost[0], dp[1] = min(dp[0] + cost[1], cost[1]);
 * 4 dp遍历顺序：从前到后
 *
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O(n)。
 * */

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    // dp数组
    vector<int> dp(n+1);
    // dp初始化
    dp[0] = cost[0], dp[1] = min(dp[0] + cost[1], cost[1]);
    // dp遍历顺序
    for (int i = 2; i <= n; i++)
        dp[i] = min(dp[i-2] + cost[i], dp[i-1] + cost[i]);// dp递推方程

    return dp[n];
}

int minCostClimbingStairs(vector<int>& cost) {
    // write code here
    int n = cost.size();

    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 0;
//         dp[2] = min(dp[0] + cost[0], dp[1] + cost[1]);

    for (int i = 2; i <= n; i++) {
        // 从哪一台阶开始爬就要算上它的cost
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    }

    return dp[n];
}