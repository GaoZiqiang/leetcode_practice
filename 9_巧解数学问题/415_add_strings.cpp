/* leetcode T415:字符串相加
 * 原题链接：https://leetcode-cn.com/problems/add-strings/
 * */

/* 方法一：模拟
 *
 * 算法思想：
 * 核心：
 * 基于竖式加法计算原理，逐位相加，进位
 *
 * 要点：
 * 1 如何将string字符串的每一位转换为int类型：
 * num[i] - '0'
 * 2 进位问题
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，n = max(len1, len2)。
 * 空间复杂度：O(1)。
 *
 * */

// 实现方法
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addStrings(string num1, string num2) {
    int i = num1.size() - 1, j = num2.size() - 1, add = 0;
    string ans = "";
    while (i >= 0 || j >= 0 || add != 0) {
        int n1 = num1[i] >= 0 ? num1[i] - '0' : 0;// 超出字符串/数组边界则num[i]<0?
        int n2 = num2[j] >= 0 ? num2[j] - '0' : 0;
        int bit_sum = n1 + n2 + add;// 各位相加
        ans.push_back('0' + bit_sum % 10);// 存余数s
        add = bit_sum / 10;// 计算进位
        i--;
        j--;
    }

    // 将结果进行翻转
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string num1 = "123", num2 = "458";
    cout << addStrings(num1, num2) << endl;
}