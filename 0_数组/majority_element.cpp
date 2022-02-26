/* leetcode T169:多数元素
 * 原题链接：https://leetcode-cn.com/problems/majority-element/
 * */

#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/* 方法一：哈希表法
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，遍历数组一遍，数组长度为n
 * 空间复杂度：O(n)，哈希表最多存放n-n/2个不同的键值对
 * */
int majorityElement(vector<int> nums) {
    unordered_map<int, int> counts;

    int majority = 0, cnt = 0;// 记录出现次数最多的元素和最大计数次数
    for (int num : nums) {
        ++counts[num];// 元素num的计数+1
        if (counts[num] > cnt) {// 进行打擂
            majority = num;// 暂存计数最大的元素
            cnt = counts[num];// 暂存最大计数
        }
    }

    return majority;
}


/* 方法二：排序
 *
 * 思想：
 * 如果将数组 nums 中的所有元素按照单调递增或单调递减的顺序排序，那么下标为n/2(向下取整)的元素(下标从0开始)一定是众数
 *
 * 复杂度分析：
 * 时间复杂度：O(nlogn)，数组排序的时间复杂度
 * 空间复杂度：O(logn)，使用C++自带的sort排序算法，需要额外的栈空间
 * */
int majorityElement2(vector<int> & nums) {// 引用传递
    sort(nums.begin(), nums.end());// 先进行排序

    return nums[nums.size() / 2];
}

/*测试*/
int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << "result: " << majorityElement(nums) << endl;
    cout << "result2: " << majorityElement(nums) << endl;
}