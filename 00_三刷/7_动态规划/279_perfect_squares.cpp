/* leetcode T279:完全平方数
 * 原题链接：https://leetcode.cn/problems/perfect-squares/
 * */

/* 方法一：动态规划--类似于T343:整数拆分
 *
 * 算法思想：与T322零钱兑换相同的思路
 *
 * 复杂度分析：
 * 时间复杂度：O(n*n)。
 * 空间复杂度：O(n)，dp数组。
 * */

#include <vector>

using namespace std;

int numSquares(int n) {
    vector<int> dp(n+1, n+1);// dp[i]理论上不会超过n+1

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int m = i * i;// 第i个完全平方数
        for (int j = m; j <= n; j++) {// n为我们的target
            dp[j] = min(dp[j], dp[j-m] + 1);
        }
    }

    return dp[n];
}