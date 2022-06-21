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

// 我的解法：动态规划
// 基于最大递增子序列的方法
// 每次只考虑i之前的[0~i-1)之间的dp即可
int rob(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n+2);

    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i < n+2; i++) {
        int num = nums[i-2];
        for (int j = 0; j < i-1; j++) {// [0,i-1) 不包含i-1
            dp[i] = max(dp[i], dp[j]+num);
        }
    }

    return max(dp[n], dp[n+1]);// 注意返回值 最后一个元素可能选也可能不选 dp[i]并没有继承dp[i-1]的状态
}

// 方法三：参考：https://programmercarl.com/0198.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D.html#%E6%80%9D%E8%B7%AF
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return nums[0];

    vector<int> dp(n);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);// dp[i]可以继承dp[i-1]的状态
    }

    return dp[n-1];
}