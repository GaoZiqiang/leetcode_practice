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
 * */

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