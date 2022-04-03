/* leetcode T349:两个数组的交集
 * 原题链接：https://leetcode-cn.com/problems/intersection-of-two-arrays/
 * */

/* 方法一：暴力遍历法
 *
 * 算法思想：
 * 关键点：
 * 1 结果使用unordered_set存储 不用手动去重
 * 2 nums1数组使用unordered_set做临时存储，unordered_set的find查找时间复杂度为O(1) 高于vector
 *
 * 存在问题：
 * unorder_set存储基于hash表，生成hash表的key也是需要时间开销的
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，
 * 空间复杂度：O(n)，set和vector。
 * */

#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> res_set;
    // nums1数组去重
    unordered_set<int> nums1_set(nums1.begin(), nums1.end());

    // 查看nums2数组中的元素是否存在于nums1数组中
    for (auto x : nums2) {
        if (nums1_set.find(x) != nums1_set.end())// unorder_set查询的时间复杂度为O(1) 高于vector
            res_set.insert(x);
    }

    vector<int> res_vec(res_set.begin(), res_set.end());

    return res_vec;
}