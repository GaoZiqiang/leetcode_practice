/* leetcode T344:反转字符串
 * 原题链接：https://leetcode-cn.com/problems/reverse-string/
 * */

/* 方法一：双指针法
 *
 * 算法思想：
 * 双指针+swap三元素交换
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，
 * 空间复杂度：O(1)。
 * */

#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++, r--;
    }
    return;
}