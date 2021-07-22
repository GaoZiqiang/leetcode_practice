/* leetcode T69:Sqrt(x的平方根)
 * 原题链接：https://leetcode-cn.com/problems/powx-n/
 * */

#include <math.h>
#include <iostream>

/* 方法一：袖珍计算器算法
 *
 * 分析：
 * 该方法借助指数函数exp和对数函数ln的组合近似替代平方根函数，参考方法一：https://leetcode-cn.com/problems/sqrtx/solution/x-de-ping-fang-gen-by-leetcode-solution/
 *
 * 复杂度分析：
 * 时间复杂度：O(1) 因为内置函数exp和log一班都很快，可将时间复杂度视为O(1)；
 * 空间复杂度：O(1)；
 *
 * 该方法的弊端：
 * 由于计算机无法存储浮点数的精确值（浮点数的存储方法可以参考 IEEE 754，这里不再赘述），
 * 而指数函数和对数函数的参数和返回值均为浮点数，因此运算过程中会存在误差。
 * */
int solution1(int x) {
    /*特殊情况*/
    if (x == 0)
        return x;

    int ans = exp(0.5 * log(x));// 这里的ans是浮点数的近似值

    /*防止精度误差导致结果偏小*/
    return ((long long) ((ans + 1) * (ans + 1)) <= x ?ans + 1 : ans);
}

/* 方法二：二分查找法
 *
 * 分析：
 * 关键：x的平方根ans满足ans^2 <= x，根据这点我们可以通过二分查找法不断缩小ans的范围。
 * 主要思想同二分查找法。
 *
 * 复杂度分析：
 * 时间复杂度：O(log x) 查找分为每次缩小一半，log x次便可以完成查找；
 * 空间复杂度：O(1)
 *
 * */
int solution2(int x) {
    if (x == 0)
        return x;

    int l = 0, r = x, ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((long long)(mid * mid) <= x) {
            ans = mid;
            l = mid + 1;// 为什么不是l = mid
        }else {
            r = mid - 1;
        }
    }

    return ans;
}

/*测试*/
int main() {
    int x = 15;
    // func(x);
    // std::cout << solution1(x) << std::endl;
    std::cout << solution2(x) << std::endl;
}
