/* leetcode T215:数组中的第K个最大元素
 * 原题链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：基于快速排序+二分
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

// 分割
int partition(vector<int>& a, int low, int high) {
    int target = a[low];

    // 从大到小排序
    while (low < high) {
        while (low < high && a[high] <= target) --high;// 小值在右边
        a[low] = a[high];
        while (low < high && a[low] >= target) ++low;// 大值在左边
        a[high] = a[low];
    }

    a[low] = target;

    return low;
}

// 快排递归+二分优化
int quickSort(vector<int>& a, int index, int low, int high) {
    // 递归终止条件
    if (low >= high) return a[low];

    int mid = partition(a, low, high);

    if (mid == index- 1) return a[mid];
    // 只递归一半区间
    return mid < index - 1 ? quickSort(a, index, mid + 1, high) : quickSort(a, index, low, mid - 1);
}

// 主函数
int findKthLargest(vector<int>& nums, int k) {
    return quickSort(nums, k, 0, nums.size() - 1);
}

// 我的写法
int partition(vector<int>& nums, int low, int high) {
    int target = nums[low];
    while (low < high) {
        while (low < high && nums[high] <= target) --high;
        nums[low] = nums[high];
        while (low < high && nums[low] >= target) ++low;
        nums[high] = nums[low];
    }
    nums[low] = target;
    return low;
}

int quickSort(vector<int>& nums, int k, int low, int high) {
    if (low >= high) return nums[low];
    int mid = partition(nums, low, high);
    if (mid == k - 1) return nums[mid];

    return mid < k - 1 ? quickSort(nums, k, mid + 1, high) : quickSort(nums, k, low, mid - 1);
}

int findKthLargest(vector<int>& nums, int k) {
    return quickSort(nums, k, 0, nums.size() - 1);
}