/* leetcode T53:最大子数组和
 * 原题链接：https://leetcode.cn/problems/maximum-subarray/
 * */

/* 方法一：贪心算法
 *
 * 核心思想：参考https://www.programmercarl.com/0053.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C.html#%E8%B4%AA%E5%BF%83%E8%A7%A3%E6%B3%95
 * 贪心贪在哪里？
 * -->只要子数组和count<0 则立即舍弃该子数组
 * 局部最优怎么找？
 * -->使用result存放最大值，只要count>result-->及时更新result即可
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个元素至多访问一次。
 * 空间复杂度：O(1)。
 *
 * 方法二：动态规划
 *
 * 算法思想：
 * dp[i]：前i个元素和
 * 核心：
 * 比较dp[i-1]+nums[i] 和nums[i]的大小：如果dp[i-1]+nums[i]比nums[i]还小，还不如nums[i]自己干 从自己开始重新起一个子数组
 * -->状态转移方程：dp[i] = max(dp[i-1]+nums[i], nums[i])
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个元素至多访问一次。
 * 空间复杂度：O(1)。
 * */


#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int result = INT32_MIN;
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        count += nums[i];
        if (count > result) result = count;// 更新result
        if (count < 0) count = 0;
    }

    return result;
}

// 方法二：动态规划
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int result = nums[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + nums[i], nums[i]);// 状态转移方程
        if (dp[i] > result) result = dp[i];
    }

    return result;
}
