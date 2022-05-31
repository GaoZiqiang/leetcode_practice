/* leetcode T47:全排列II
 * 原题链接：https://leetcode.cn/problems/permutations-ii/
 * */

/* 方法一：基于回溯法
 *
 * 算法思想：
 *
 * 关键点：
 * 1 去重
 *  借鉴T491:递增子序列去重的方法，设置临时unordered_set
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，所有节点遍历一遍。
 * 空间复杂度：O(n)，递归所需空间。
 * */

#include <vector>

using namespace std;

void dfs(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& ans) {
    if (path.size() == nums.size()) {
        ans.push_back(path);
        return;
    }

    unordered_set<int> uset;// 去重，保证同一个元素只有一个
    for (int i = 0; i < nums.size(); i++) {
        if (!uset.empty() && uset.find(nums[i]) != uset.end()) continue;
        if (used[i] == true) continue;
        path.push_back(nums[i]);
        uset.insert(nums[i]);
        used[i] = true;// 访问标记置为false
        dfs(nums, used, path, ans);
        path.pop_back();
        used[i] = false;// 访问标记恢复为false
    }

    return;
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    // sort(nums.begin(), nums.end());

    vector<int> path;
    vector<vector<int>> ans;
    vector<bool> used(nums.size(), false);

    dfs(nums, used, path, ans);

    return ans;
}