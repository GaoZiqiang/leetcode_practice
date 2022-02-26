/* leetcode T9:回文数
 * 原题链接：https://leetcode-cn.com/problems/palindrome-number/
 * */

#include <vector>
#include <stdio.h>
#include <iostream>

/* 方法一：int转字符串法
 *
 * 方法二：反转一半数字法
 *
 * 算法思想：
 * 对于数字 1221，如果执行 1221 % 10，我们将得到最后一位数字 1，要得到倒数第二位数字，
 * 我们可以先通过除以 10 把最后一位数字从 1221 中移除，1221 / 10 = 122，
 * 再求出上一步结果除以 10 的余数，122 % 10 = 2，就可以得到倒数第二位数字。
 * 如果我们把最后一位数字乘以 10，再加上倒数第二位数字，1 * 10 + 2 = 12，
 * 就得到了我们想要的反转后的数字。如果继续这个过程，我们将得到更多位数的反转数字。
 *
 * 如何判断反转数字的位数已经达到原始数字位数的一半？
 * 当原始数字小于或等于反转后的数字时，就意味着我们已经处理了一半位数的数字了
 *
 * 复杂度分析：
 * 时间复杂度：O(logn)，对于每次迭代，我们会将输入除以 1010，因此时间复杂度为 O(logn)。
 * 空间复杂度：O(1)。我们只需要常数空间存放若干变量。
 * */



#define MAXSIZE 20

using namespace std;

long * getDigits(long);
// int转字符串法
bool isPalindromeNumber(long * nums);
// 反转一半数字法
bool isPalindromeNumber(int x);// 函数重载

int main() {
    // 方法一：
    long xs = 123212;
    long * nums;
    nums = getDigits(xs);

    printf("nums[0]: %ld\n",*(nums+2));

    if (isPalindromeNumber(nums))
        printf("xs is\n");
    else
        printf("xs is not\n");

    delete [] nums;

    // 方法二：
    int x = 12321;
    if (isPalindromeNumber(x))
        printf("x is\n");
    else
        printf("x is not\n");

}

// 翻转一半数字
bool isPalindromeNumber(int x) {
    // 1 边界条件
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;
    // 2 判断
    int revertedNumber = 0;
    while (x > revertedNumber) {// 退出条件x <= revertedNumber
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    return x == revertedNumber || x == revertedNumber / 10;
}



// 将整型数转换为字符串
long * getDigits(long xs) {
    int digits;
    long * nums = new long[MAXSIZE];// 开辟内存
    int i = 0;
    nums[i] = xs % 10;
    while (xs /= 10) {
        i++;
        digits++;
        nums[i] = xs % 10;
        printf("nums[i]: %ld\n",xs % 10);
    }

    return nums;
}

// 双指针法
bool isPalindromeNumber(long * nums) {
    int low = 0, high = 5;
    while (low <= high) {
        if (nums[low] != nums[high])
            break;
        low++;
        high--;
    }
    if (low > high)
        return true;
    if (low < high)
        return false;
}