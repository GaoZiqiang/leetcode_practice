/* T78:子集 https://leetcode.cn/problems/subsets/
 *
 * 方法一：递归+回溯
 *
 * 算法思想：基于T77组合问题:https://leetcode.cn/problems/combinations/
 * 本题只是将[0,nums.size()]之间的所有长度的组合全部遍历一遍
 *
 * 关键点：
 *
 * 时间复杂度：O(n*Cn,k * k)，共Cn,k种组合，每种组合需要O(k)的时间复杂度，n次。
 * 空间复杂度：O(n)，递归的层数。
 * */

#include <vector>

using namespace std;

void dfs(vector<int>& nums, int start, int len, vector<int>& path, vector<vector<int>>& ans) {
    if (path.size() >= len) {
        ans.push_back(path);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        dfs(nums, i+1, len, path, ans);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> path;
    vector<vector<int>> ans;

    for (int i = 0; i <= nums.size(); i++) {
        path.clear();
        dfs(nums, 0, i, path, ans);
    }

    return ans;
}