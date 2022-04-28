/* T402:移掉 K 位数字 https://leetcode-cn.com/problems/remove-k-digits/
 *
 * 方法一：单调栈
 * 算法思想：
 * 尽量删掉高位较大的数字(思想转换：当出现从左到右递减时间，基于"尽量删掉高位较大的数字"这一思想-->删掉较大的数字)
 * -->单调栈-->单调增栈
 * -->if (stack.top() < num[i])-->退栈
 *
 * 关键点：
 * 1 本题中栈存放元素num[i]
 * 2 本题中栈使用string/vector实现
 * 3 前导0问题
 * 4 k > 0 && 栈不为空问题
 *
 * 时间复杂度：O(n)。
 * 空间复杂度：O(n)，stack栈空间(?string字符串其实只占用一个指针而已)。
 * */

#include <string>

using namespace std;

string removeKdigits(string num, int k) {
    int n = num.size();
    string stack;

    for (int i = 0; i < n; i++) {
        while (!stack.empty() && stack.back() > num[i] && k > 0) {
            stack.pop_back();
            k--;
        }
        // 前导0问题(栈为空且num[i]=='0')-->不入栈即可
        if (stack.empty() && num[i] == '0') continue;
        stack.push_back(num[i]);
    }

    // k > 0 且栈不为空
    while (!stack.empty() && k-- > 0) stack.pop_back();

    // k == 0 栈为空/不为空
    return stack.empty() ? "0" : stack;
}