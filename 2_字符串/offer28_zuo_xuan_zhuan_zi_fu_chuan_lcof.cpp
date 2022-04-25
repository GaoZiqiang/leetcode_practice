/* leetcode offer28-II:左旋转字符串
 * 原题链接：https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 * */

/* 方法一：局部翻转+整体翻转
 * 算法思想：
 * 具体步骤为：
 * 1 反转区间为前n的子串
 * 2 反转区间为n到末尾的子串
 * 3 反转整个字符串
 * 最后就可以得到左旋n的目的，而不用定义新的字符串，完全在本串上操作。
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O(1)。
 * */


#include <string>

using namespace std;

string reverseLeftWords(string s, int k) {
    reverse(s.begin(), s.begin() + k);// 先翻转前k个元素
    reverse(s.begin() + k, s.end());// 再翻转k后面的元素
    reverse(s.begin(), s.end());// 最后翻转整个字符串s
    return s;
}