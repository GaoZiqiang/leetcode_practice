/* leetcode T442:数组中重复的数据
 * 原题链接：https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
 * */

/* 方法一：原地哈希
 *
 * 算法思想：参考https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/solution/by-ac_oier-0m3c/
 * 核心：
 * 在数值范围和下标范围大小相同的情况下(利用值域与数字下标空间大小的等同关系)，重复元素满足：
 * nums[i] == nums[nums[i]-1]
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个元素只遍历一遍。
 * 空间复杂度：O(n)，ans数组。
 * */

#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int t = nums[i];
        if (t < 0 || t - 1 == i) continue;// 已访问元素
        if (t == nums[t-1]) {// 重复元素 nums[i] == nums[nums[i]-1]
            ans.push_back(t);
            nums[i] *= -1;// 做已访问标记
        } else {// 交换两个位置的元素
            int c = nums[t-1];
            nums[t-1] = t;
            nums[i--] = c;// i-- 该nums[i]位置处的元素需要重新检验--因为已经换成了新元素
        }
    }

    return ans;
}