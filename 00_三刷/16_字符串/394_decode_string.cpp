/* leetcode T394:字符串解码
 * 原题链接：https://leetcode.cn/problems/decode-string/
 * */

/* 方法一：递归
 *
 * 算法思想：
 * 用递归依次解析[]内部的子串
 *
 * 优化：
 * 递归子函数不再设置形参，将其作为类的成员变量-->这样可以极大地节省递归时的栈空间大小，避免爆栈
 *
 * 复杂度分析：
 * 时间复杂度：O(len(s) + height)，每个字符都要遍历一遍。
 * 空间复杂度：O(height)，取决于递归栈的深度。
 *
 * */

class Solution {
public:
    string src;
    size_t ptr;

    int getDigits() {
        int ret = 0;
        while (ptr < src.size() && isdigit(src[ptr])) {
            ret = ret * 10 + src[ptr++] - '0';
        }
        return ret;
    }

    string getString() {
        if (ptr == src.size() || src[ptr] == ']') {
            // String -> EPS
            return "";
        }

        char cur = src[ptr]; int repTime = 1;
        string ret;

        if (isdigit(cur)) {
            // String -> Digits [ String ] String
            // 解析 Digits
            repTime = getDigits();
            // 过滤左括号
            ++ptr;
            // 解析 String
            string str = getString();
            // 过滤右括号
            ++ptr;
            // 构造字符串
            while (repTime--) ret += str;
        } else if (isalpha(cur)) {
            // String -> Char String
            // 解析 Char
            ret = string(1, src[ptr++]);
        }

        return ret + getString();
    }

    string decodeString(string s) {
        src = s;
        ptr = 0;
        return getString();
    }
};