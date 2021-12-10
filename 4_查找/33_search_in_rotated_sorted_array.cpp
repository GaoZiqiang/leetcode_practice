/* leetcode T33:搜索旋转排序数组
 * 原题链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：基于二分查找
 *
 * 算法思想：
 * 二分查找的核心：
 * 第一，在有序序列中进行；第二，可以通过丢弃一半元素的方式降低算法运行成本；
 *
 * 关键点一：无论nums[mid]在哪个位置，总有一边/一半是有序的，第一步是确定有序的那一边；
 * 关键点二：判断target是否在有序的那一半，若在，则继续在有序的那一边进行二分查找；若不在，则到另一边（无序）进行查找；
 *
 * 复杂度分析：
 * 时间复杂度：O(logn)，每次都是二分查找。
 * 空间复杂度：O(1)，原地操作。
 *
 * 参考视频讲解：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-leetcode-solut/
 * */

// 实现方法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        if (1 == nums.size())
            return target == nums[0] ? 0 : -1;

        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) return mid;
            if (nums[0] <= nums[mid]) {
                if (target >= nums[0] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[nums.size() - 1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};