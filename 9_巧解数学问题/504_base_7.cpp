/* leetcode T504:七进制数
 * 原题链接：https://leetcode-cn.com/problems/base-7/
 * */

/* 方法一：端除法
 *
 * 算法思想：
 * 核心：
 * 端除法
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，遍历完一遍即可。
 * 空间复杂度：O(n)，stack。
 *
 * */

#include <stack>
#include <iostream>
#include <string>

using namespace std;

string convertToBase7(int num) {
    // 0和负数
    if (0 == num) return "0";
    bool is_neg = false;
    if (num < 0) {
        num = -num;
        is_neg = true;
    }
    stack<string> rmds;
    int mch = num, rmd = 0;// mch：除数 rmd：余数
    // 端除法
    while (mch > 0) {
        rmd = mch % 7;// 余数
        mch = mch / 7;// 商
        rmds.emplace(to_string(rmd));// 入栈
    }

    string res;
    if (is_neg)
        res += "-";
    while (!rmds.empty()) {
        res += rmds.top();
        rmds.pop();
    }

    return res;
}

int main() {
    cout << convertToBase7(-101) << endl;
}
