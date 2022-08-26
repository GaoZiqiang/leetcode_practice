/* leetcode T581:最短无序连续子数组
 * 原题链接：https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/
 * */

/* 方法一：基于排序
 *
 * 算法思想：
 * 原数组可以分为三部分：有序1:无序:有序2
 * 对原数组进行排序之后：有序1:有序:有序2
 *
 * 发生变化的是中间的部分-->
 * 因此只需要比较排序前后未发生变化的部分两个边界即可
 *
 * 复杂度分析：
 * 时间复杂度：O(nlogn)，排序(nlogn)+遍历O(n)。
 * 空间复杂度：O(n)，额外数组。
 * */

#include <bits/stdc++.h>

int findUnsortedSubarray(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    if (is_sorted(nums.begin(), nums.end())) return 0;

    vector<int> sortedNums(nums);
    sort(sortedNums.begin(), sortedNums.end());

    int n = nums.size();
    int left = 0;
    while (left < n) {
        if (nums[left] == sortedNums[left]) left++;
        else break;
    }

    int right = n - 1;
    while (right >= 0) {
        if (nums[right] == sortedNums[right]) right--;
        else break;
    }

    return right - left + 1;
}