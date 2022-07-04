/* leetcode T896:单调数列
 * 原题链接：https://leetcode-cn.com/problems/monotonic-array/
 * */

/* 方法一：两次遍历和一次遍历
 *
 * 算法思想：基于“举反例排除法”，有一个不满足，则排除
 * 1 验证是否单调递增 只要有一个nums[i] > nums[i+1] --> 不满足单调递增 --> 排除
 * 2 验证是否单调递减 只要有一个nums[i] < nums[i+1] --> 不满足单调递减 --> 排除
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O(1)。
 *
 * 方法二：单调栈
 *
 * 算法思想：
 * 利用单调栈来检验数组中的元素是否单调
 * 分两次
 *
 * 复杂度分析：
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 * */

#include <vector>
#include <stack>

using namespace std;

// 两次遍历
bool isMonotonic(vector<int>& nums) {
    int n = nums.size();
    bool dec = true, inc = true;

    // 两次遍历
    // 验证是否单调递减
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i-1]) {
            dec = false;
            break;
        }
    }

    // 验证是否单调递增
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i-1]) {
            inc = false;
            break;
        }
    }

    return dec || inc;
}

// 一次遍历
bool isMonotonic(vector<int>& nums) {
    int n = nums.size();
    bool dec = true, inc = true;

    // 一次遍历
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i-1]) {// 验证是否单调递减
            dec = false;
        }
        if (nums[i] < nums[i-1]) {// 验证是否单调递增
            inc = false;
        }
        // 提前退出遍历
        if (!dec && !inc) return false;
    }

    return dec || inc;
}

// 方法二：两次单调栈判断
bool isMonotonic(vector<int>& nums) {
    int n = nums.size();

    bool dec = true, inc = true;

    stack<int> stack;

    // 先判断是否为单调减
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && stack.top() < nums[i]) {
            stack.pop();
        }
        stack.push(nums[i]);
    }

    if (stack.size() < n) dec = false;

    // 清空stack
    while (!stack.empty()) stack.pop();

    // 判断是否为单调增
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && stack.top() > nums[i]) {
            stack.pop();
        }
        stack.push(nums[i]);
    }

    if (stack.size() < n) inc = false;

    return inc || dec;
}