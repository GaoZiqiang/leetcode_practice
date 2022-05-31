/* leetcode T46:全排列
 * 原题链接：https://leetcode-cn.com/problems/permutations/
 * */

/* 方法一：基于回溯法
 *
 * 算法思想：
 *
 * 关键点：
 *  因为全排列需要“重复”使用之前访问过的元素，因此这里纵向递归时的stard_idx为stard_idx+1，而不再是
 *  组合问题的i+1
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，所有节点遍历一遍。
 * 空间复杂度：O(n)，递归所需空间。
 *
 * 方法二：借助标记数组
 *
 * 关键点：参考https://programmercarl.com/0046.%E5%85%A8%E6%8E%92%E5%88%97.html#%E6%80%9D%E8%B7%AF
 * 1 横向单层遍历都从0开始，取消start
 * 2 标记数组在入path数组前置为true，退出path数组时置为false
 * */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 回溯
void backTracking(vector<int>& nums, int n, int start_idx, vector<vector<int>>& res) {
    // 终止条件
    if (start_idx>=n) {
        res.push_back(nums);
        return;
    }

    // 单层循环
    for (int i = start_idx; i < n; i++) {
        // 数据处理
        swap(nums[start_idx], nums[i]);// n = nums.size()
        // 递归
        backTracking(nums, n, start_idx + 1, res);
        // 回溯
        swap(nums[start_idx], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    backTracking(nums, n, 0, res);
    return res;
}

int main() {
    int a[5]={1,2,3,4,5};
    do{
        for(int i=0;i<5;i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }while(next_permutation(a,a+5));
    return 0;
}

// 方法二：借助标记数组
void dfs(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& ans) {
    if (path.size() == nums.size()) {
        ans.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i] == true) continue;
        path.push_back(nums[i]);
        used[i] = true;// 访问标记置为false
        dfs(nums, used, path, ans);
        path.pop_back();
        used[i] = false;// 访问标记恢复为false
    }

    return;
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<int> path;
    vector<vector<int>> ans;
    vector<bool> used(nums.size(), false);

    dfs(nums, used, path, ans);

    return ans;
}