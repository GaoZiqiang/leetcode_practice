/* T31:下一个排列 https://leetcode-cn.com/problems/next-permutation/
 * 思路：参见回溯专题
 * 参考：https://www.bilibili.com/video/BV1dT4y1y78u
 * * 方法：两遍扫描O(n)
 * */

void nextPermutation(vector<int>& nums) {
    // 1 找第一个逆序元素
    int k = nums.size() - 1;
    while (k - 1 >= 0 && nums[k-1] >= nums[k]) k--;// nums[k-1]即为目标
    // 2 交换
    if (k  - 1 < 0) {
        reverse(nums.begin(), nums.end());
    } else {
        int tmp = nums[k-1];
        // 找比目标大且最小的元素--从后往前找
        int m = nums.size() - 1;
        while (m >= 0 && nums[m] <= tmp) m--;
        swap(nums[k-1], nums[m]);// 交换
        // 3 翻转
        reverse(nums.begin() + k, nums.end());
    }
    return;
}