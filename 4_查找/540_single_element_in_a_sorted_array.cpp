/* leetcode T540:有序数组中的单一元素
 * 原题链接：https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：基于二分查找
 *
 * 算法思想：
 * 我们考虑数组中的最后一个元素x：在最小值右侧的元素，它们的值一定都小于等于x；而在最小值左侧的元素，
 * 它们的值一定都大于等于x
 *
 * 关键点一：看nums[mid]右边的元素个数的奇偶情况来决定single元素所在侧
 *
 * 关于二分查找的一点思考：
 * 1 二分查找的本质是通过砍掉一半，使每次的查找长度变为原来的一半，从而实现O(logn)的时间复杂度
 * 2 “砍掉一半”的判断标准：
 * 二分查找的多数算法都是在有序数组中进行，因此有序数组中“砍掉一半”的判断标准基本都是对nums[mid]和target进行
 * 大小判断，从而决定砍掉哪一半
 * 3 在本题中，题目没有提供直接通过对nums[mid]和target进行大小判断就能够决定砍掉哪一半的“切入口”
 * 因此，本题需要别的条件进行决定：
 * 看nums[mid]右边的元素个数的奇偶情况
 * 若右边为偶数个，则single元素在左边；反之，在右边
 * nums[mid]右边的元素个数的奇偶情况还要根据nums[mid]和nums[mid-1]、nums[mid+1]的大小关系决定--即mid指针的位置
 *
 * 复杂度分析：
 * 时间复杂度：O(logn)，每次都是二分查找。
 * 空间复杂度：O(1)，原地操作。
 *
 * 参考讲解：https://leetcode-cn.com/problems/single-element-in-a-sorted-array/solution/you-xu-shu-zu-zhong-de-dan-yi-yuan-su-by-leetcode/
 * */

// 实现方法
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.empty())
            return -1;
        if (1 == nums.size())
            return nums[0];

        int left = 0, right = nums.size() - 1;
        while (left < right) {// 不能取等号
            int mid =  (right + left) / 2;
            bool half_len_even = (right - mid) % 2 == 0 ? 1 : 0;// mid右边元素个数的奇偶
            if (nums[mid] == nums[mid + 1]) {
                if (half_len_even) {// 实际single元素在右边--half_len_even为偶数，实际nums[mid+1]右边有奇数个元素
                    left = mid + 2;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] == nums[mid - 1]) {
                if (half_len_even) {// single元素在左边
                    right = mid - 2;
                } else {
                    left = mid + 1;
                }
            } else {
                return nums[mid];
            }
        }
        return nums[left];
    }
};