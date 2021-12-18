/* leetcode T198:打家劫舍
 * 原题链接：https://leetcode-cn.com/problems/house-robber/
 * */

/* 方法一：动态规划--基于递归
 *
 * 算法思想：
 * 核心：
 * 没走到一个房子都有两种选择，
 * 一，不抢--则当前最大累积金额为dp[i-1]--即上一次的最大金额
 * 二，抢--则当前最大累积金额为当前nums[i]+dp[i-2]--因为不能相邻，因此抢劫nums[i]就不能抢劫nums[i-1]--只能取dp[i-2]
 *
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，遍历完一遍即可。
 * 空间复杂度：O(n)，vector<int> dp。
 *
 * */


// 实现方法1
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n + 1, 0);// dp[i]当前最大累积金额
        dp[1] = nums[0];// dp从index = 1开始
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);// nums[i - 1]即为dp数组中的第i个房子
        }
        return dp[n];
    }
};

// 实现方法2--空间优化
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];
        int pre2 = 0, pre1 = 0, cur;
        for (int i = 0; i < n; i++) {
            cur = max(pre2 + nums[i], pre1);
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};