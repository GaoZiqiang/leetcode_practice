/* leetcode T41:缺失的第一个正数
 * 原题链接：https://leetcode.cn/problems/first-missing-positive/
 * */

/* 方法一：原地哈希&元素置换
 *
 * 算法思想：
 * 利用原地哈希的思想，将符合nums[i]==i+1的元素"归位"到正确位置
 * -->这样能够保证1~n范围内的元素是按照顺序排列的
 * -->然后遍历查询，查看不满足nums[i]==i+1的元素，即为缺失元素
 * -->如果1~n范围内的元素都存在-->则第一个缺失的正数为n+1
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个元素只遍历一遍。
 * 空间复杂度：O(1)。
 * */

#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    // 调整元素位置
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
    }

    // 逐位检查 不满足nums[i]==i+1的位置/元素
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) return i + 1;// 第一个缺失的就是最小的
    }

    // 1-n范围内的元素都存在
    return n+1;
}