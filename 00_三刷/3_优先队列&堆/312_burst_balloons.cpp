/* leetcode T312:戳气球
 * 原题链接：https://leetcode.cn/problems/burst-balloons/
 * */

/* 方法一：记忆化搜索
 *
 * 算法思想：
 * 1 分别计算一个元素的前缀积和后缀积
 * 2 计算前缀积/后缀积时使用贪心算法：
 * pre[i+1] = pre[i] * nums[i];
 * post[i-1] = post[i] * nums[i];
 * 3 然后遍历一次求每个元素的前缀积和后缀积的成积
 *
 * 时间复杂度：O(n^3)。
 * 空间复杂度：O(n^2)。
 *
 * */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> vals;

public:
    int helper(int left, int right) {
        // 中间没有位置添加气球了
        if (left >= right - 1) return 0;

        // 剪枝操作
        if (res[left][right] != -1) return res[left][right];

        for (int i = left + 1; i < right; i++) {
            int sum = vals[left] * vals[i] * vals[right];
            sum += helper(left, i) + helper(i, right);
            res[left][right] = max(res[left][right], sum);
        }

        return res[left][right];
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // 辅助数组vals
        vals.resize(n+2);

        for (int i = 1; i <= n; i++) {
            vals[i] = nums[i-1];
        }
        vals[0] = vals[n+1] = 1;

        // 为res赋初值
        res.resize(n + 2, vector<int>(n + 2, -1));// 初始化为-1

        return helper(0, n + 1);
    }
};