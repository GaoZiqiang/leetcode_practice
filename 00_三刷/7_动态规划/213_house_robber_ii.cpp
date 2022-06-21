/* leetcode T213:打家劫舍II
 * 原题链接：https://leetcode.cn/problems/house-robber-ii/
 * */

/* 方法一：动态规划--基于T198:打家劫舍
 *
 * 算法思想：
 * 与T198:打家劫舍不同之处在于这是一个环形结构
 * 以最后一个元素nums[n-1]为例，如果选择该元素，则第一个元素nums[0]就不能选(违背了隔一个取一个的原则)
 * -->此时考虑，只从[0,n-2]这n-1个元素中选择--含头不含尾
 *
 * 以此类推，不取nums[0]，从[1,n-1]这n-1个元素中选择--含尾不含头
 *
 * -->最后的结果取两种情况的最大结果即可。
 *
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，遍历完一遍即可。
 * 空间复杂度：O(n)，vector<int> dp。
 *
 * */

#include <vector>

using namespace std;

// T198:打家劫舍的基础函数
int robRange(vector<int>& nums, int start, int end) {
    if (start == end) return nums[start];
    vector<int> dp(nums.size());

    dp[start] = nums[start];
    dp[start+1] = max(nums[start], nums[start+1]);// 注意start==end的情况

    for (int i = start+2; i <= end; i++) {
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);// dp[i]可以继承dp[i-1]的状态
    }

    return dp[end];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // 两种情况
    int res1 = robRange(nums, 0, n-2);
    int res2 = robRange(nums, 1, n-1);

    return max(res1, res2);
}