/* T40:组合总和II https://leetcode.cn/problems/combination-sum-ii/
 *
 * 方法一：递归+回溯
 *
 * 算法思想：参考https://programmercarl.com/0040.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII.html#%E5%9B%9E%E6%BA%AF%E4%B8%89%E9%83%A8%E6%9B%B2
 *
 * 关键点：
 * 同一树层的重复元素去重:candidates[i] == candidates[i-1])
 * 同一树枝的重复元素去重:path[i] == path[i-1]
 *
 * 另外方法:借助used数组
 *
 * 时间复杂度：O(Cn,k * k)，共Cn,k种组合，每种组合需要O(k)的时间复杂度。
 * 空间复杂度：O(n)，递归的层数。
 * */

#include <vector>

using namespace std;

void dfs(vector<int>& candidates, int target, int start, int& sum, vector<int>& path, vector<vector<int>>& ans) {
    if (sum > target) return;
    if (sum == target) {
        sort(path.begin(), path.end());
        if (std::find(ans.begin(), ans.end(), path) != ans.end()) return;
        ans.push_back(path);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i-1]) continue;// 同一层重复
        sum += candidates[i];
        path.push_back(candidates[i]);
        dfs(candidates, target, i+1, sum, path, ans);// 这里的start取i-->可以重复candidates[i]这一个元素-->下一轮只能选i以及i之后的元素-->避免重复过多
        sum -= candidates[i];
        path.pop_back();
    }

    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<int> path;
    vector<vector<int>> ans;
    int sum = 0;

    dfs(candidates, target, 0, sum, path, ans);

    return ans;
}

// 解法二：借助used数组
void dfs(vector<int>& candidates, vector<bool>& used, int target, int start, int& sum, vector<int>& path, vector<vector<int>>& ans) {
    if (sum > target) return;
    if (sum == target) {
        sort(path.begin(), path.end());
        if (std::find(ans.begin(), ans.end(), path) != ans.end()) return;
        ans.push_back(path);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i-1] && used[i-1] == false) continue;// 同一层重复
        sum += candidates[i];
        path.push_back(candidates[i]);
        used[i] = true;// 同一树枝
        dfs(candidates, used, target, i+1, sum, path, ans);// 这里的start取i-->可以重复candidates[i]这一个元素-->下一轮只能选i以及i之后的元素-->避免重复过多
        sum -= candidates[i];
        used[i] = false;// 同一层
        path.pop_back();
    }

    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<bool> used(candidates.size(), false);

    vector<int> path;
    vector<vector<int>> ans;
    int sum = 0;

    dfs(candidates, used, target, 0, sum, path, ans);

    return ans;
}