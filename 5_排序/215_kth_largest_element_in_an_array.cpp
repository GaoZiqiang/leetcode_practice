/* leetcode T215:数组中的第K个最大元素
 * 原题链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：基于快速排序
 *
 * 算法思想：
 * 关键点一：比较枢pivot的下标序号index--序列是从小到大排序，第k个大的元素下标为len - k，
 * 当枢pivot的下标index等于len - k时，此时的元素即为我们要查找的第k个大的元素
 * 关键点二：使用快速排序中的partition算法确定pivot的index
 * 关键点三：二分法，使用二分法确定partition算法在哪一个子序列中进行
 *
 * 改进一：
 * int mid = partition(nums, left, right);只需要在if判断前总的执行一次即可，避免多次执行，浪费时间
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，最多需要遍历1+2+3+...+n次，最少需要1+1+1+...+1=n次。
 * 空间复杂度：O(1)，原地操作。
 * */

int findKthLargest(vector<int>& nums, int k) {
    int target = nums.size() - k;
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        // 这样只计算一次partition即可
        int mid = partition(nums, low, high);
        if (mid == target) {
            return nums[target];
        } else if (target < mid) {
            high = mid - 1;
            // mid = partition(nums, low, mid - 1);// 多浪费一次计算partition的时间
        } else {
            low = mid + 1;
            // mid = partition(nums, mid + 1, high);
        }
    }
    return nums[low];
}

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[low];
    while (low < high) {
        // 先从左边开始--nums[low]被拿去作为pivot了，需要一个nums[high]来填充
        while (low < high && nums[high] >= pivot) --high;
        nums[low] = nums[high];
        // 然后在比较右边
        while (low < high && nums[low] <= pivot) ++low;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}
