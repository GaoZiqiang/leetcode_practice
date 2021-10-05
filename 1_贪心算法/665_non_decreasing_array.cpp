/* leetcode T665:非递减数列
 * 原题链接：https://leetcode-cn.com/problems/non-decreasing-array/
 * */

#include <vector>
#include <stdio.h>

/* 方法一：贪心算法
 * 遇到递减的情况时（nums[i] > nums[i + 1]），要么将前面的元素缩小，要么将后面的元素放大。
 *
 * 注意：
 * 1 如果将nums[i]缩小，可能会导致其无法融入前面已经遍历过的非递减子数列；
 * 2 如果将nums[i + 1]放大，可能会导致其后续的继续出现递减；
 *
 * 核心思想：
 * 在遍历时，每次需要看连续的三个元素，也就是瞻前顾后，遵循以下两个原则:
 * 1 需要尽可能不放大nums[i + 1]，这样会让后续非递减更困难；
 * 2 如果缩小nums[i]，但不破坏前面的子序列的非递减性；
 *
 * 算法思想：--一个大的前提：前面i-1个元素已经是非递减的，即：nums[i-1] <= nums[i]
 * 遍历数组，如果遇到递减：--nums[i-1] <= nums[i] > nums[i+1]
 *   还能修改：
 *   1 情形一：nums[i+1] >= nums[i-1]
 *     将nums[i]缩小至nums[i + 1]；
 *   2 情形二：nums[i+1] < nums[i-1]
 *     将nums[i + 1]放大至nums[i]；--因为已经满足nums[i-1] <= nums[i]
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，一次遍历。
 * 空间复杂度：O(1)，不需要额外空间。
 * */

using namespace std;

bool isNonDecArray(vector<int> & nums) {
    bool flag = (nums[0] <= nums[1]) ? true : false;// 可修改
    // 循环遍历的范围:nums[1]~nums[len-1]
    for (int i = 1; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i+1]) {
            if (flag) {
                if (nums[i+1] < nums[i-1])// 情形二
                    nums[i+1] = nums[i];
                else                      // 情形一
                    nums[i] = nums[i+1];
                flag = false;// 用掉修改机会--不可以再次修改
            } else
                return false;
        }
    }
    return true;
}

int main() {
    vector<int> nums = {4,2,1};
    if (isNonDecArray(nums))
        printf("is NonDecArray\n");
    else
        printf("Not NonDecArray\n");
}