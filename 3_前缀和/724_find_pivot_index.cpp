/* leetcode T724:寻找数组的中心下标
 * 原题链接：https://leetcode-cn.com/problems/find-pivot-index/
 * */

/* 方法一：前缀和
 * 算法思想：
 * 左侧和==右侧和 返回
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O(1)。
 * */


int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // for (auto& num : nums)
    //     sum += num;

    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        left += nums[i];
        right = sum - left;
        if (left - nums[i] == right) {// 左和==右和
            return i;
        }
    }

    return -1;
}