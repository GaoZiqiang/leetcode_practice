/* leetcode T300:最长递增子序列
 * 原题链接：https://leetcode.cn/problems/longest-increasing-subsequence/
 * */

/* 方法一：动态规划
 *
 * 算法思想：
 * 关键在于对于每个nums[i]，选择不同的起点，可以得到不同长度的子序列
 * -->因此，每个元素nums[i]都要取nums[i]之前的所有元素中子序列最长的那个元素
 *
 * 动规五部曲：
 * 1 dp[i]的定义
 *   dp[i]表示i之前包括i的以nums[i]结尾最长上升子序列的长度
 * 2 状态转移方程
 *   位置i的最长升序子序列等于j从0到i-1各个位置的最长升序子序列 + 1 的最大值。
 *   所以：if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
 *   即：
 *   for (int i = 1; i < n; i++) {
 *      for (int j = 0; j < i; j++) {
 *          if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
 *      }
 *      ans = max(ans, dp[i]);// 更新最长子序列长度 dp[i]:0~i之间的最长子序列长度
 *    }
 * 3 dp[i]的初始化
 *   每一个i，对应的dp[i]（即最长上升子序列）起始大小至少都是1。
 * 4 确定遍历顺序
 *   dp[i] 是有0到i-1各个位置的最长升序子序列 推导而来，那么遍历i一定是从前向后遍历。
 *   j其实就是0到i-1，遍历i的循环在外层，遍历j则在内层
 *
 * 关键点：
 *   1 dp数组初始化，每个元素初始值为1(不同于之前的0，因为每个元素都可以构成一个长度为1的子序列)；
 *   2 使用ans存放结果，对每一个元素i结尾的子序列都要比较。
 *
 * 复杂度分析：
 * 时间复杂度：O(n*n)。
 * 空间复杂度：O(n)。
 * */

#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 1);// 每个dp[i]初始值为1-->即使nums[i]不比前面的任何一个元素大，其nums[i]元素本身仍然能构成长度为1的子序列
    int ans = 1;// 子序列长度至少为1

    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);// 更新最长子序列长度 dp[i]:0~i之间的最长子序列长度
    }

    return ans;
}