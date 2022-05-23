/* T738:单调递增的数字 https://leetcode.cn/problems/monotone-increasing-digits/
 *
 * 方法一：贪心算法
 *
 * 算法思想：参考https://www.programmercarl.com/0738.%E5%8D%95%E8%B0%83%E9%80%92%E5%A2%9E%E7%9A%84%E6%95%B0%E5%AD%97.html#%E8%B4%AA%E5%BF%83%E7%AE%97%E6%B3%95
 * 1 从后往前遍历，只要高位比低位小-->低位-1 同时记录遍历到的最新的高位
 * 2 然后将所记录的高位全部变成'9'
 *
 * 关键：
 * 1 将int类型的整数n转换为string字符串处理，转换完后再变为整数
 *
 * 时间复杂度：O(n)。
 * 空间复杂度：O(1)。
 * */

int monotoneIncreasingDigits(int n) {
    string strN = to_string(n);
    int last = strN.size();

    for (int i = strN.size() - 1; i > 0; i--) {
        if (strN[i-1] > strN[i]) {
            strN[i-1]--;// 低位-1
            last = i;// 更新last
        }
    }

    for (int i = last; i < strN.size(); i++) {
        strN[i] = '9';// 所有高位替换为'9'
    }

    return stoi(strN);
}