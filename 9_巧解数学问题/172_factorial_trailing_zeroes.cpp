/* leetcode T172:阶乘后的零
 * 原题链接：https://leetcode-cn.com/problems/factorial-trailing-zeroes/
 * */

/* 方法一：计算因子5
 *
 * 算法思想：
 * 核心：
 * 阶乘的每个尾数0都是*10得到的，而10是由于2*5得到的，而5的个数一定是少于2的个数的，
 * 因此只需要统计因子5的个数即可
 *
 * 复杂度分析：
 * 时间复杂度：O(n^2)，大约是n^2次。
 * 空间复杂度：O(1)。
 *
 * */

#include <iostream>

int trailinigZeroes(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int mch = i;
        // 分析每一个元素的因子是否含有5--准确的说是因子5的个数
        while (mch % 5 == 0) {
            count++;
            mch = mch / 5;
        }
    }
    return count;
}

int main() {
    std::cout << trailinigZeroes(5) << std::endl;
}