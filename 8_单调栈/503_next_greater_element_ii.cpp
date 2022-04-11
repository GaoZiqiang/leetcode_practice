/* leetcode T503:下一个更大元素II
 * 原题链接：https://leetcode-cn.com/problems/next-greater-element-ii/
 * */

/* 方法一：单调栈+循环数组
 *
 * 算法思想：
 * 用栈存放每个数组元素
 * 每新元素入栈前，将栈中比新元素小的元素退栈 这些退栈的元素的next greater num就是新元素
 *
 * 关键点：
 * 两链表合并时创建一个新链表记录合并后的链表
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，我们需要遍历该数组中每个元素最多 2 次，每个元素出栈与入栈的总次数也不超过 4 次。
 * 空间复杂度：O(n)，栈。
 * */

#include <vector>
#include <stack>

using namespace std;

// 方法一
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < 2 * n; j++) {
            if (nums[j % n] > nums[i]) {
                res[i] = nums[j % n];
                break;
            }
        }
    }

    return res;
}

// 方法二：单调栈
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> stack;

    for (int i = 0; i < 2 * n; i++) {// i取[0, 2n)解决循环问题
        while (!stack.empty() && nums[stack.top()] < nums[i % n]) {
            res[stack.top()] = nums[i % n];
            stack.pop();// 将栈中比nums[i % n]小的元素出栈
        }
        stack.push(i % n);
    }

    return res;
}
