/* leetcode T50:Pow(求幂)
 * 原题链接：https://leetcode-cn.com/problems/powx-n/
 *
 * 方法一：快速幂+递归
 * 快速幂算法的本质是分治算法。Pow(x,n)
 *
 * 为提高算法计算速度，我们不再采用逐个x相乘的方法，从x 开始，每次直接把上一次的结果进行平方。
 * 但要注意将n分为偶数和奇数两种情况。
 *
 * 整体算法思想如下：
 * 1 当我们要计算x^n时，我们可以先递归地计算出y = x^⌊n/2⌋，其中 ⌊a⌋ 表示对a 进行下取整；
 * 2 根据递归计算的结果，如果 n 为偶数，那么 x^n = y^2；如果n 为奇数，那么 x^n = y^2 * x；
 * 3 递归的边界为 n = 0，任意数的 0 次方均为 11。
 *
 * 当指数 n 为负数时，我们可以计算 x^−n 再取倒数得到结果，因此我们只需要考虑 n 为自然数的情况。
 *
 * 复杂度分析：
 * 时间复杂度：O(log n)，递归的层数，因为是以平方的形式逐渐相乘，直到x^n，共计log n次递归。
 * 空间复杂度：O(log n)，递归的层数，递归函数会使用栈作为辅助空间。
 *
 * ***补充：递归算法的时间复杂度计算问题（参考知乎：https://www.zhihu.com/question/63075755）
 * 递归算法的时间复杂度本质上是要看: 递归的次数 * 每次递归中的操作次数
 * */
#include <iostream>

using namespace std;

class Solution {
public:
    double baseMul(int x, int n) {
        if (n == 0)
            return 1.0;
        /*分治：一分为二*/
        double y = baseMul(x,n/2);// 递归调用log n次
        /*依次递归*/
        if (n % 2 == 0)
            return y * y;// n为偶数
        else
            return y * y * x;// n为奇数
    }

    double myPow(int x,int n) {
        /*考虑特殊情况*/
        if (x ==0 || x == 1)
            return x;

        /*n为正数*/
        if (n >= 0)
            return baseMul(x,n);
        /*n为负数*/
        else
            return 1.0 / baseMul(x,n);
    }
};
