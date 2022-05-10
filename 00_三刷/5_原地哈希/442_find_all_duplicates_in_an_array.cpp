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
 *
 * 方法二：使用正负号作标记
 *
 * 算法思想：
 * 每个元素第一次出现时对其作-号标记
 * -->如何元素有两个，则其第二次出现时一定是-号-->找到了出现两次的元素
 * -->反之，只有一个的元素不会出现第二次
 *
 * 复杂度同方法一
 * */

#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;

    // 第一遍：调整元素位置 不匹配/重复元素调到后面去
    for (int i = 0; i < n; i++) {
        while (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);// 不合适的元素全部推到后面去
    }

    // 找出不匹配/重复元素
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) ans.push_back(nums[i]);
    }

    return ans;
}

// 方法二：使用正负号作标记
vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int t = abs(nums[i]);// 元素值
        if (nums[t-1] > 0) {// 该元素第一次出现--为+
            nums[t-1] = -nums[t-1];// 加-号标记
        } else {// 第二次出现--为-(第一次出现时加的-号)
            ans.push_back(t);
        }
    }

    return ans;
}