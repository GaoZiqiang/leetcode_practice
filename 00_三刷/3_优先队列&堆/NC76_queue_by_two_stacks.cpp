/* NC76 用两个栈实现队列
 * 原题链接：https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=117&tqId=37774&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 参考题解：https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=117&tqId=37774&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * */

#include <stack>

using namespace std;

class Solution {
public:
    void push(int node) {
        stack1.push(node);// 直接push进第一个栈
    }

    int pop() {
        // 将第一个栈中的元素依次push进第二个栈
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        // 将第二个栈的栈顶元素pop出
        int res = stack2.top();
        stack2.pop();
        // 再将第二个栈中的元素依次push进第一个栈
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};