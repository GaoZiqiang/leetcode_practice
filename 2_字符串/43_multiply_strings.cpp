/* leetcode T43:字符串相乘
 * 原题链接：https://leetcode.cn/problems/multiply-strings/
 * */

/* 方法一：逐位求乘积
 *
 * 算法思想：
 * 先将每个位求乘积
 * 然后计算进位情况
 *
 * 复杂度分析：
 * 时间复杂度：O(m*n)，m和n分别为两个字符串的长度。
 * 空间复杂度：O(m+n)。
 * */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    int n1 = num1.size(), n2 = num2.size();
    vector<int> ansArr = vector<int>(n1+n2);

    // 每个位置相乘
    for (int i = n1-1; i >= 0; i--) {
        int x = num1.at(i) - '0';
        for (int j = n2-1; j >= 0; j--) {
            int y = num2.at(j) - '0';
            ansArr[i+j+1] += x * y;// 是+=
        }
    }

    // 计算每个数位的值
    for (int i = n1+n2-1; i > 0; i--) {
        ansArr[i-1] += ansArr[i] / 10;// 进位给高位
        ansArr[i] %= 10;// 余数给本位
    }

    int index = ansArr[0] == 0 ? 1 : 0;// 最高位是否有进位-->确定ans的起始点
    string ans;
    while (index < n1+n2) {
        ans.push_back(ansArr[index]);
        index++;
    }
    for (auto& c : ans) c += '0';// int转换为string

    return ans;
}