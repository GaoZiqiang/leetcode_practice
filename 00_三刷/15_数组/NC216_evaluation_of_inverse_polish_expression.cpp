/* NC216 逆波兰表达式求值
 * 原题链接：https://www.nowcoder.com/practice/885c1db3e39040cbae5cdf59fb0e9382?tpId=117&tqId=39420&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3D%25E6%25B3%25A2%25E5%2585%25B0%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=%E6%B3%A2%E5%85%B0
 * */

#include <stack>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param tokens string字符串vector
     * @return int整型
     */
    int evalRPN(vector<string>& tokens) {
        // write code here
        int n = tokens.size();
        stack<int> stack;

        for (int i = 0; i < n; i++) {
            string s = tokens[i];
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int x1 = stack.top();
                stack.pop();
                int x2 = stack.top();
                stack.pop();

                if (s == "+") stack.push(x2 + x1);// 注意两个操作数的前后顺序
                else if (s == "-") stack.push(x2 - x1);
                else if (s == "*") stack.push(x2 * x1);
                else stack.push(x2 / x1);
            }
                // 操作数入栈
            else {
                stack.push(stoi(s));
            }
        }

        int ans = stack.top();
        stack.pop();

        return ans;
    }
};