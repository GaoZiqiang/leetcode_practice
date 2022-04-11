/* leetcode T1:两数之和
 * 原题链接：https://leetcode-cn.com/problems/two-sum/
 * */

/* 方法一：哈希表法
 *
 * 算法思想：
 * 关键点：
 * 1 nums[i]元素值做key，元素index做value
 * 2 find()函数查找时间复杂度为O(1)
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，find()函数查找时间复杂度为O(1)。
 * 空间复杂度：O(n)，map数组。
 * */


#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // 记录原来元素的index
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++) {
            auto it = map.find(target - nums[i]);// find()判断键值是否存在 // find()查找时间为O(1)
            if (it != map.end()) {
                return {it->second, i};
            }
            map.insert({nums[i], i});
        }

        return {};
    }
};