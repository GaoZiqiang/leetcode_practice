/* leetcode T454:四数相加II
 * 原题链接：https://leetcode-cn.com/problems/4sum-ii/submissions/
 * */

/* 方法一：哈希表法
 *
 * 算法思想：参考两数之和解法
 * 关键点：
 * 1 去重
 * 2 双指针while(left < right) 此时l==r不能取 即while (left <= right)
 *
 * 复杂度分析：
 * 时间复杂度：O(n^2)，两层for循环+find()的O(1)复杂度。
 * 空间复杂度：O(n)，unordered_map。
 * */


#include <vector>
#include <unordered_map>

using namespace std;

int forSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int res = 0;
    unordered_map<int, int> map;

    // 先存入nums1和nums2两个数组的元素和
    for (auto& n1 : nums1) {
        for (auto& n2 : nums2) {
            map[n1 + n2]++;// 统计n1和n2的和出现的次数
        }
    }

    // 再通过nums3和nums4反向查询
    for (auto& n3 : nums3) {
        for (auto& n4 : nums4) {
            // 查看nums1和nums2中是否有满足条件的和
            auto it = map.find(0 - (n3 + n4));
            if (it != map.end()) {
                // 统计次数
                res += map[0 - (n3 + n4)];
            }
        }
    }

    return res;
}