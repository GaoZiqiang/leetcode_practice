/* T39:组合总和 https://leetcode-cn.com/problems/combination-sum/
 * 思路：https://app.yinxiang.com/Home.action?_sourcePage=kyeeqHe6-DniMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=Q1bMCpORWMw3yWPvuidLz-TPR6I9Jhx8&login=true&username=gaoziqianghi%40163.com#n=17deef15-5735-4894-971a-60cc0b0e1623&s=s3&t=9b8b7b13-7239-446d-8ad5-eddfabb8fa22&ses=4&sh=3&sds=5&
 * 方法：回溯法(n*2^n)
 * */

void dfs(vector<int>& candidates, int& start, int target, int& sum, vector<int>& path, vector<vector<int>>& ans) {
    if (sum == target) {
        ans.push_back(path);
        return;
    }
    if (sum > target) {
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        sum += candidates[i];
        path.push_back(candidates[i]);
        dfs(candidates, i, target, sum, path, ans);// new_start = i-->允许元素重复
        sum -= candidates[i];
        path.pop_back();
    }
    return;
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> path;
    int start = 0, sum = 0;
    dfs(candidates, start, target, sum, path, ans);
    return ans;
}