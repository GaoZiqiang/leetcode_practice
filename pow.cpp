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
 * */
#include <iostream>

using namespace std;

class Solution {
public:
    double baseMul(int x, int n) {
        if (n == 0)
            return 1.0;
        /*分治：一分为二*/
        double y = baseMul(x,n/2);
        /*依次递归*/
        if (n % 2 == 0)
            return y * y;// n为偶数
        else
            return y * y * x;// n为奇数
    }

    double myPow(int x,int n) {
        /*n为正数*/
        if (n >= 0)
            return baseMul(x,n);
        /*n为负数*/
        else
            return 1.0 / baseMul(x,n);
    }
};

/*测试*/
int main() {
    Solution *solution = new Solution();

    int x =2;
    int n = 10;

    cout << x << "^" << n << " is " << solution->myPow(x,n) << endl;
}