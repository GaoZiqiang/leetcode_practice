/* leetcode T34:在排序数组中查找元素的第一个和最后一个位置
 * 原题链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * */

/* 方法一：二分法+顺序查找
 *
 * 算法思想：
 * 1 先使用二分查找找到第一个target元素
 * 2 然后使用线性查找找到数组中第一个和最后一个target
 *
 * 关键点：
 * 数组下标越界
 *
 * 复杂度分析：
 * 时间复杂度：O(logn)，
 * 空间复杂度：O(1)。
 * */


#include <vector>
#include <stdio.h>

using namespace std;

// 我的写法
vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1};
    int n = nums.size();
    // 排序
    // sort(nums.begin(), nums.end());
    int low = 0, high = n - 1;
    int ledge = -1, redge = -1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (target == nums[mid]) {
            // mid在最左边
            if (mid - 1 >= 0 && nums[mid-1] != nums[mid]) {
                ledge = mid;
                while(mid < n && nums[mid] == target) {
                    // ans++;
                    mid++;
                }
                redge = mid - 1;
                return {ledge, redge};
                // mid在最右边
            } else if (mid + 1 < n && nums[mid+1] != nums[mid]) {
                redge = mid;
                while (mid >= 0 && nums[mid] == target) {
                    // ans++;
                    mid--;
                }
                ledge = mid + 1;
                return {ledge, redge};
                // mid在中间
            } else {
                // 往左边找
                int origin_mid = mid;
                while (mid >= 0 && nums[mid] == target) {
                    // ans++;
                    mid--;
                }
                ledge = mid + 1;
                // 往右边找
                mid = origin_mid;
                while (mid < n && nums[mid] == target) {
                    // ans++;
                    mid++;
                }
                redge = mid - 1;
                return {ledge, redge};
            }
        } else if (target > nums[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return {ledge, redge};
}

// 方法
vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) {
        return {-1, -1};
    }

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        int num = nums[mid];
        if (num < target) {
            left += 1;
        } else if (num > target) {
            right -= 1;
        } else {
            int start = -1, end = -1;
            if (mid > 0 && nums[mid-1] != num) {// 左 mid-1<0?
                start = mid;
                while(mid < n && nums[mid] == num) mid++;
                end = mid - 1;
            } else if (mid < n - 1 && nums[mid+1] != num) {// 右边 mid+1>n-1?
                end = mid;
                while (mid >= 0 &&nums[mid] == num) mid--;
                start = mid + 1;
            } else {// 中间
                int tmp = mid;
                while (mid >= 0 && nums[mid] == num) mid--;
                start = mid + 1;
                while (tmp < n && nums[tmp] == num) tmp++;
                end = tmp - 1;
            }
            return {start, end};
        }
    }

    return {-1, -1};
}

// 官方题解
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        int left = findLeft(nums, target);
        if (left == -1) {
            return {-1, -1};
        }
        int i = left;
        for (; i < nums.size(); i++) {
            if (nums[i] != target) {
                break;
            }
        }

        return {left, i - 1};
    }
    int findLeft(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = (l + h) /2;
            if (m == 0 && nums[m] == target) {
                return m;
            } else if (m - 1 >= 0 && nums[m] == target && nums[m-1] < nums[m]) {
                return m;
            } else if (nums[m] == target){
                h = m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return -1;
    }
};