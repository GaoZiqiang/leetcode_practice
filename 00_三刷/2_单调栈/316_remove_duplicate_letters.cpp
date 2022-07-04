/* leetcode T316:去除重复字母
 * 原题链接：https://leetcode.cn/problems/remove-duplicate-letters/
 * */

/* 方法一：单调栈
 *
 * 算法思想：参考https://leetcode.cn/problems/remove-duplicate-letters/solution/qu-chu-zhong-fu-zi-mu-by-leetcode-soluti-vuso/
 *
 * 关键点：
 * 1 使用数组实现单调栈的
 * 2 记录每个字符的出现次数和访问标记
 *
 * 复杂度分析：
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 * */


#include <string>
#include <vector>

using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> vis(26), num(26);// 每个字符的访问标记和在字符串中的个数

    for (char ch : s) {
        num[ch - 'a']++;// 统计字符串中每个字符元素的个数
    }

    string stk;
    for (char ch : s) {
        // 元素ch不在栈中
        if (!vis[ch - 'a']) {
            // 保证字典序最小
            while (!stk.empty() && stk.back() > ch) {
                // 该back元素在字符串s的后边还有
                if (num[stk.back() - 'a'] > 0) {
                    vis[stk.back() - 'a'] = 0;// 将访问标记置为未访问
                    stk.pop_back();
                } else {// 该back元素在字符串s的后边已经没有了，就不用退栈了
                    break;
                }
            }
            // ch元素入栈并置访问标记为已访问
            vis[ch - 'a'] = 1;
            stk.push_back(ch);
        }
        // 遍历完之后字符元素的个数减1
        num[ch - 'a'] -= 1;
    }

    return stk;
}