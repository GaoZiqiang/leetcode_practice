/* leetcode T377:组合总和Ⅳ
 * 原题链接：https://leetcode.cn/problems/combination-sum-iv/
 * */

/* 方法一：动态规划
 *
 * 算法思想：基于T518:零钱兑换II
 * dp[i][j]：使用前i种面额，实现j总金额的组合数
 *
 * 但是：不同之处在于T518:零钱兑换II(T518为组合问题)，该题实际为一个排列问题。
 * -->
 * 如果求组合数就是外层for循环遍历物品，内层for遍历背包。
 * 如果求排列数就是外层for遍历背包，内层for循环遍历物品。
 * for (int j = 0; j <= target; j++) {// 外层遍历背包
 *  for (int i = 1; i <= n; i++) {// 内层遍历物品
 *      int num = nums[i-1];
 *      if (j < num) dp[j] = dp[j];
 *      else {
 *              if (dp[j-num] + dp[j] > INT_MAX) continue;// 防止数值过大
 *              dp[j] = dp[j-num] + dp[j];
 *      }
 *  }
 * }
 *
 * 复杂度分析：
 * 时间复杂度：O(m*n)，m为target，n为nums.size()。
 * 空间复杂度：O(m*n)，dp数组。
 * */

#include <vector>

using namespace std;

typedef long long ll;

int combinationSum4(vector<int>& nums, int target) {
    int n = nums.size();

    vector<ll> dp(target+1, 0);

    dp[0] = 1;

    for (int j = 0; j <= target; j++) {// 外层遍历背包
        for (int i = 1; i <= n; i++) {// 内层遍历物品
            int num = nums[i-1];
            if (j < num) dp[j] = dp[j];
            else {
                if (dp[j-num] + dp[j] > INT_MAX) continue;// 防止数值过大
                dp[j] = dp[j-num] + dp[j];
            }
        }
    }

    return dp[target];
}