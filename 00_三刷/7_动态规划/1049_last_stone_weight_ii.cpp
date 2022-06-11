/* leetcode T1049:最后一块石头的重量II
 * 原题链接：https://leetcode.cn/problems/last-stone-weight-ii/
 * */

/* 方法一：动态规划
 * 算法思想：基于T416分割等和子集的算法思想
 * 本题的关键在于算法思路的转换：如何将本题转化为分割等和子集的问题
 *
 * 本题的题眼在于"粉碎"，粉碎即为两数相减。-->将stones数组划分为两个子集-->求两个子集和的差。
 * 题目所求"返回此石头最小的可能重量"即为使两个子集和的差尽可能小。
 *
 * stones数组的和为sum，两个子集和sum1和sum2，sum1 sum2要么二者都为sum/2，要么一个大于sum/2，一个小于sum/2；
 * 根据sum1+sum2=sum
 * -->sum1-sum=sum-sum1-sum1=sum-2*sum1
 * sum-2*sum1即为本题所求返回此石头最小的可能重量"。根据题意，sum-2*sum1>=0-->sum1<=sum/2。
 * int sum = accumulate(stones.begin(), stones.end(), 0);
 * int target = sum / 2;// 这里取整即可 target可以小于sum的1/2
 *
 * 该题就变成了01背包问题：
 * dp[i][j]：前i个数中，是否存在和为j的组合情况。
 * -->状态转移方程：
 * for (int i = 1; i <= n; i++) {
 *  int stone = stones[i-1];
 *  for (int j = 0; j <= target; j++) {
 *      if (j < stone) dp[i][j] = dp[i-1][j];
 *      else dp[i][j] = dp[i-1][j] || dp[i-1][j-stone];
 *  }
 * }
 *
 * 最后的结果为：
 * for (int i = target; i >= 0; i--) {
 *  if (dp[n][i] == true) return sum - 2 * i;// 取尽可能大的sum1
 * }
 *
 * 时间复杂度：O(n*target)：。
 * 空间复杂度：O(n*target)：数组。
 * */
#include <vector>

using namespace std;

int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;// 这里取整即可 target可以小于sum的1/2

    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        int stone = stones[i-1];
        for (int j = 0; j <= target; j++) {
            if (j < stone) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-stone];
        }
    }

    for (int i = target; i >= 0; i--) {
        if (dp[n][i] == true) return sum - 2 * i;// 取尽可能大的sum1
    }

    return 0;
}

// 存储空间优化
int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;// 这里取整即可 target可以小于sum的1/2

    vector<bool> dp(target+1, false);

    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        int stone = stones[i-1];
        for (int j = target; j >= 0; j--) {
            if (j < stone) dp[j] = dp[j];
            else dp[j] = dp[j] || dp[j-stone];
        }
    }

    for (int i = target; i >= 0; i--) {
        if (dp[i] == true) return sum - 2 * i;// 取尽可能大的sum1
    }

    return 0;
}