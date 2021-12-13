/* leetcode T154:寻找旋转排序数组中的最小值 II
 * 原题链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：基于T33:搜索旋转排序数组和T81:搜索旋转排序数组 II
 *
 * 算法思想：
 * 我们考虑数组中的最后一个元素x：在最小值右侧的元素，它们的值一定都小于等于x；而在最小值左侧的元素，
 * 它们的值一定都大于等于x
 *
 * 关键点一：通过比较nums[mid]与nums[right]二者之间的关系，确定最小值所在区间
 *
 * 复杂度分析：
 * 时间复杂度：O(logn)，每次都是二分查找。
 * 空间复杂度：O(1)，原地操作。
 *
 * 参考视频讲解：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/solution/xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-de-zui--16/
 * */

// 实现方法
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return -1;
        if (1 == nums.size())
            return nums[0];
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[right]) {// 抛弃mid右侧区间
                right = mid;// nums[mid]可能为最小值
            } else if (nums[mid] > nums[right]) {// 抛弃mid左侧区间
                left = mid + 1;
            } else {// right--
                --right;
            }
        }
        return nums[left];
    }
};