/* leetcode T448到所有数组中消失的数字
 * 原题链接：https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/
 * */

/* 方法一：原地哈希&元素置换
 *
 * 算法思想：
 * 利用原地哈希的思想，将符合nums[i]==i+1的元素"归位"到正确位置
 * -->这样能够保证1~n范围内的元素是按照顺序排列的
 * -->然后遍历查询，查看不满足nums[i]==i+1的元素，即为缺失元素
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个元素只遍历一遍。
 * 空间复杂度：O(n)。
 * */

#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        while (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            ans.push_back(i+1);// nums[i]为重复数字
        }
    }

    return ans;
}