/* leetcode T343:整数拆分
 * 原题链接：https://leetcode-cn.com/problems/integer-break/
 * */

/* 方法一：动态规划
 *
 * 算法思想：
 * 对于每一个状态dp[i]，i可以进行划分为i = k + (i - k)
 * 可以分为三种情况：
 *  1 dp[k] * dp[i-k]// k和i-k都分割
 *  2 k * dp[i-k]// 只对i-k进行分割
 *  3 k * (i - k)// k和i-k都不分割
 *
 * 复杂度分析：
 * 时间复杂度：O(n*n)。
 * 空间复杂度：O(n)。
 * */

#include <vector>

using namespace std;

int integerBreak(int n) {
    // dp数组
    vector<int> dp(n+1);
    // dp初始化
    dp[1] = dp[2] = 1;
    // 遍历顺序
    for (int i = 3; i <= n; i++)
        for (int k = 1; k < i; k++)
            dp[i]= max(max(dp[k] * dp[i-k], k * dp[i-k]),max(dp[i], k * (i - k)));// 递推方程
    return dp[n];
}