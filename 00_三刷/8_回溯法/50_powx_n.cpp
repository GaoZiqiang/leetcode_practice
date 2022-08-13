/* leetcode T50:Pow(x, n)
 * 原题链接：https://leetcode.cn/problems/powx-n/
 * */

/* 方法一：快速幂+递归
 *
 * 算法思想：
 *
 * 复杂度分析：
 * 时间复杂度：O(logn)，递归的层数。
 * 空间复杂度：O(logn)，递归所需空间。
 * */

class Solution {
public:
    double quickPow(double x, int N) {
        if (N == 0) return 1.0;

        double y = quickPow(x, N/2);

        return N % 2 == 0 ? y * y : y * y * x;
    }
    double myPow(double x, int n) {
        return n < 0 ? 1.0 / quickPow(x, n) : quickPow(x, n);
    }
};