/* leetcode T239:滑动窗口最大值
 * 原题链接：https://leetcode.cn/problems/sliding-window-maximum/
 * */

/* 方法一：基于优先队列
 *
 * 算法思想：
 * 关键优化点：相邻的两个窗口有k-1个共同元素
 *
 * 时间复杂度：O(nlogn)。
 * 空间复杂度：O(n)。
 *
 * */

#include <bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();

    priority_queue<pair<int, int>> q;

    for (int i = 0; i < k; i++) {
        q.emplace(nums[i], i);
    }

    vector<int> ans;
    ans.push_back(q.top().first);// 第一组的最大值
    for (int i = k; i < n; i++) {
        q.emplace(nums[i], i);
        // 将不在当前滑动窗口范围内的排除
        while (q.top().second <= i - k) q.pop();
        ans.push_back(q.top().first);// 剩下元素中最大元即为当前窗口的最大值
    }

    return ans;
}