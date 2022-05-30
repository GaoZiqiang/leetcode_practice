/* T491:递增子序列 https://leetcode.cn/problems/increasing-subsequences/
 *
 * 方法一：递归+回溯
 *
 * 算法思想：基于T40:组合总和II的同一树层的去重问题
 *
 * 关键点：
 * 1 同一树层的重复元素去重
 *  不同于T40和T90子集问题，不能对原数组进行排序，所以不能使用nums[i]==nums[i-1]进行去重
 * -->使用临时set存放本层元素
 * 2 比大小
 *  比较每到一个新层之后nums[i]与path数组的最后一个元素path.back()即可
 *  -->满足nums[i]>=path.back()
 *
 * 时间复杂度：O(Cn,k * k)，共Cn,k种组合，每种组合需要O(k)的时间复杂度。
 * 空间复杂度：O(n)，递归的层数。
 * */


#include <vector>

using namespace std;

void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& ans) {
    if (path.size() >= 2) {
        ans.push_back(path);
    }
    if (path.size() >= nums.size()) return;

    // 保存本层元素
    unordered_set<int> uset;
    for (int i = start; i < nums.size(); i++) {
        // 不满足递增或者重复元素
        if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) continue;
        uset.insert(nums[i]);// 保存本层元素
        path.push_back(nums[i]);
        dfs(nums, i+1, path, ans);
        path.pop_back();
    }

    return;
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> path;
    vector<vector<int>> ans;

    dfs(nums, 0, path, ans);

    return ans;
}