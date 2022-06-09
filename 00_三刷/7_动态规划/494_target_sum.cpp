/* leetcode T494:目标和
 * 原题链接：https://leetcode-cn.com/problems/target-sum/
 * */

/* 方法一：回溯法
 *
 * 算法思想：
 * 构造一棵关于'+''-'两种操作的回溯二叉树
 * 对于每个元素nums[i]都有'+'和'-'两种选择
 * 每一条路径上的运算符序列构成一个表达式
 *
 * 时间复杂度：O(2^n)：每个元素有两种选择。
 * 空间复杂度：O(n)：递归。
 *
 * 方法二：动态规划
 * 这个问题使用动态规划的关键在于如何进行问题的转换：
 * 记数组的元素和为sum，添加-号的元素之和为neg，则其余添加+的元素之和为sum−neg，
 * 得到的表达式的结果为
 * (sum−neg)−neg=sum−2⋅neg=target
 * 即neg = (sum - target) / 2
 *
 * 该问题便可以转换为：
 * 在数组nums中选取若干元素，使得这些元素之和等于neg，计算选取元素的方案数。
 * 由此问题转换为了动态规划问题。
 *
 * dp五要素：
 * dp[i][j]：在数组nums的前i个数中选取元素，使得这些元素之和等于j的方案数；
 * dp初始化：dp[0][0] = 1，其他为0；
 * 状态转移方程：
 * dp[i][j] = dp[i-1][j] j < nums[i]--nums[i]一定不能加入
 *          = dp[i-1][j] + dp[i-1][j-nums[i]]--nums[i]可加入也可不加入
 *
 * 时间复杂度：O(n*neg)；
 * 空间复杂度：O(n*neg)：数组
 * */

#include <vector>

using namespace std;

// 方法一：回溯法
void backTracking(vector<int>& nums, int target, int i, int sum, int& ans) {
    if (i >= nums.size() && sum == target) {
        ans++;
        return;
    }
    if (i >= nums.size())
        return;

    backTracking(nums, target, i + 1, sum + nums[i], ans);
    backTracking(nums, target, i + 1, sum - nums[i], ans);

    return;
}
int findTargetSumWays(vector<int>& nums, int target) {
    int ans = 0;
    backTracking(nums, target, 0, 0, ans);
    return ans;
}

// 方法二：动态规划
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = 0;
    for (auto& x : nums)
        sum += x;
    int diff = sum - target;
    if (diff < 0 || diff % 2 != 0)
        return 0;
    int neg = diff / 2;
    vector<vector<int>> dp(n+1, vector<int>(neg+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int num = nums[i-1];
        for (int j = 0; j <= neg; j++) {
            if (num > j) {
                dp[i][j] = dp[i-1][j];
            } else{// 加入元素i或者不加入
                dp[i][j] = dp[i-1][j-num] + dp[i-1][j];
            }
        }
    }
    return dp[n][neg];
}

// 版本二：使用一维数组
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum - target < 0 || (sum - target) % 2 != 0) return 0;// sum - target = 2 * leftsum 应该为偶数
    int leftsum = (sum - target) / 2;
    vector<int> dp(leftsum+1, 0);

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        int num = nums[i-1];
        for (int j = leftsum; j >= 0; j--) {
            if (j < num) dp[j] = dp[j];
            else dp[j] = dp[j-num] + dp[j];
        }
    }

    return dp[leftsum];
}