/* leetcode T20:有效的括号
 * 原题链接：https://leetcode-cn.com/problems/valid-parentheses/
 * */

/* 方法一：栈的应用
 *
 * 算法思想：
 * 1 初始化一个空栈，顺序读入括号；
 * 2 若是右括号，则与栈顶元素进行匹配，分以下两种情况：
 *  ①匹配：弹出栈顶元素并进行下一个元素
 *  ②不匹配：该输入序列不合法
 * 3 若是左括号，则压入栈中；
 * 4 若是全部元素遍历完毕，栈中非空则序列不合法。
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，一次遍历。
 * 空间复杂度：O(n)。
 * */


#include <stack>

using namespace std;

bool isValid(string s) {
    if (s.size() % 2)
        return false;

    stack<char> stack;

    for (auto& c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } else {
            if (stack.empty() || (c == ')' && stack.top() != '(') || c == '}' && stack.top() != '{' || c == ']' && stack.top() != '[') {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}