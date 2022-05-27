/* T77:组合 https://leetcode.cn/problems/combinations/
 *
 * 方法一：递归+回溯
 *
 * 算法思想：参考https://programmercarl.com/0077.%E7%BB%84%E5%90%88%E4%BC%98%E5%8C%96.html#%E5%85%B6%E4%BB%96%E8%AF%AD%E8%A8%80%E7%89%88%E6%9C%AC
 *
 * 关键点：
 * 剪枝操作
 * 每一层中，处于n-(k-path.size())+1之后的元素都不必遍历了。
 *
 * 时间复杂度：O(Cn,k * k)，共Cn,k种组合，每种组合需要O(k)的时间复杂度。
 * 空间复杂度：O(n)，递归的层数。
 * */

#include <vector>

using namespace std;

void backTracking(int n, int k, int pos, vector<int>& path, vector<vector<int>>& ans) {
    // 终止条件
    if (path.size() == k) {
        ans.push_back(path);
        return;
    }

    // 横向遍历
    for (int i = pos; i <= n-(k-path.size())+1; i++) {
        path.push_back(i);
        backTracking(n, k, i+1, path, ans);
        path.pop_back();
    }

    return;
}

vector<vector<int>> combine(int n, int k) {
    vector<int> path;
    vector<vector<int>> ans;

    backTracking(n, k, 1, path, ans);

    return ans;
}