/* leetcode T416:Partition Equal Subset Sum
 * 原题链接：https://leetcode-cn.com/problems/partition-equal-subset-sum/
 * */

/* 方法一：动态规划
 * dp[i][j]：0...i个元素中，和是否为j
 * 状态转移方程：
 * dp[i][j] = dp[i-1][j]   nums[i] > j--元素nums[i]不加入
 *          = dp[i-1][j] | dp[i-1][j-nums[i]] nums[i] <= j 只要有一个为true则dp[i][j]为true
 * dp数组初始化：
 * dp[0...n][0] = true
 * dp[0][nums[0]] = true
 * 其他为false
 *
 * 时间复杂度：O(n*target)：。
 * 空间复杂度：O(n*target)：数组。
 * */

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    if (n < 2)
        return false;
    int sum = 0;
    int maxNum = 0;
    for (auto& x : nums) {
        sum += x;
        maxNum = max(maxNum, x);
    }
    if (sum % 2 != 0)
        return false;
    int target = sum / 2;
    if (maxNum > target)
        return false;
    // 上面是各种特殊情况
    vector<vector<bool>> dp(n, vector<bool>(target+1, false));
    // dp数组初始化
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][nums[0]] = true;
    // 遍历
    for (int i = 1; i < n; i++) {
        int num = nums[i];
        for (int j = 1; j <= target; j++) {
            if (num > j) {// nums[i] > target-->nums[i]不加入
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] | dp[i-1][j-num];
            }
        }
    }
    return dp[n-1][target];
}