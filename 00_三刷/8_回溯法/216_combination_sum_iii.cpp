/* T216:组合总和III https://leetcode.cn/problems/combination-sum-iii/
 *
 * 方法一：递归+回溯
 *
 * 算法思想：
 *
 * 关键点：
 * 两处剪枝操作
 * 1 每一层中，处于9-(k-path.size())+1之后的元素都不必遍历了
 * 2 有元素值大于n-sum就不用继续遍历后边的了
 *
 * 时间复杂度：O(Cn,k * k)，共Cn,k种组合，每种组合需要O(k)的时间复杂度。
 * 空间复杂度：O(n)，递归的层数。
 * */

#include <vector>

using namespace std;

void backTracking(int n, int k, int start, int& sum, vector<int>& path, vector<vector<int>>& ans) {
    if (path.size() == k) {
        if (sum == n) ans.push_back(path);
        return;
    }

    for (int i = start; i <= 9-(k-path.size())+1 && i <= n-sum; i++) {// 两处剪枝操作
        sum += i;
        path.push_back(i);
        backTracking(n, k, i+1, sum, path, ans);
        sum -= i;
        path.pop_back();
    }

    return;
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> path;
    vector<vector<int>> ans;
    int sum = 0;
    backTracking(n, k, 1, sum, path, ans);

    return ans;
}