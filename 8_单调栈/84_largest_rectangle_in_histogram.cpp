/* leetcode T84:柱状图中最大的矩形
 * 原题链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 * */

/* 方法一：单调栈
 *
 * 算法思想：参考：https://www.bilibili.com/video/BV1DJ411q7eY?spm_id_from=333.337.search-card.all.click
 * 十进制转换为二进制
 *
 * 时间复杂度：O(n)，
 * 空间复杂度：O(n)。
 *
 * */

#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    int n = heights.size();
    stack<int> stack;

    stack.push(-1);// 存入-1作为整体的左边界

    for (int i = 0; i < n; i++) {
        // 计算退栈元素的矩形面积
        while (stack.top() != -1 && heights[stack.top()] >= heights[i]) {// 退栈
            int top = stack.top();
            stack.pop();
            ans = max(ans, heights[top] * (i - stack.top() - 1));// 计算矩形面积
        }
        stack.push(i);
    }

    // 计算单调栈中元素的矩形面积
    while (stack.top() != -1) {
        int top = stack.top();
        stack.pop();
        ans = max(ans, heights[top] * (n - stack.top() - 1));
    }

    return ans;
}