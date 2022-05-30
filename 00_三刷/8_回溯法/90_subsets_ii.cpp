/* T90:子集II https://leetcode.cn/problems/subsets-ii/
 *
 * 方法一：递归+回溯
 *
 * 算法思想：基于T40:组合总和II的同一树层的去重问题
 *
 * 关键点：
 * 1 同一树层的重复元素去重:candidates[i] == candidates[i-1])
 * 2 关键点1需要注意边界条件:i > start
 * 3 nums数组需要为有序数组-->提前排序
 *
 * 另外方法:借助used数组
 *
 * 时间复杂度：O(Cn,k * k)，共Cn,k种组合，每种组合需要O(k)的时间复杂度。
 * 空间复杂度：O(n)，递归的层数。
 * */

#include <vector>

using namespace std;

void dfs(vector<int>& nums, int len, int start, vector<int>& path, vector<vector<int>>& ans) {
    if (path.size() == len) {
        ans.push_back(path);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i-1]) continue;// 同一树层重复
        path.push_back(nums[i]);
        dfs(nums, len, i+1, path, ans);
        path.pop_back();
    }

    return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<int> path;
    vector<vector<int>> ans;


    for (int i = 0; i <= nums.size(); i++) {
        path.clear();
        dfs(nums, i, 0, path, ans);
    }

    return ans;
}
