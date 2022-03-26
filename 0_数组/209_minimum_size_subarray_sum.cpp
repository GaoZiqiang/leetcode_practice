/* leetcode T209:长度最小的子数组
 * 原题链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 * */

/* 方法一：滑动窗口法
 *
 * 算法思想：
 * [start, end]维持窗口大小，当窗口中元素和sum>=target时，更新res
 * 同时start++迁移，再次调整窗口大小
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，
 * 空间复杂度：O(1)。
 * */

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = 0;
    int res = 0x3f3f3f3f, sum = nums[end];
    while (start <= end && end < n) {
        // 滑动窗口
        while (sum < target && end < n) {
            end++;
            if (end >= n)
                break;
            sum += nums[end];
        }
        // 更新最小长度res
        if (sum >= target) {
            res = min(res, end - start + 1);
            sum -= nums[start];
            start++;
        }
    }
    return res == 0x3f3f3f3f ? 0 : res;
}