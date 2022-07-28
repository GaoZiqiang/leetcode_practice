/* BM86 大数加法
 * 原题链接：https://www.nowcoder.com/practice/11ae12e8c6fe48f883cad618c2e81475?tpId=295&tqId=1061819&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 * 参考leetcode T43 字符串相乘
 * */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
//         if (s.empty() && t.empty()) return "";
//         if (s.empty() && !t.empty()) return t;
//         if (t.empty() && !s.empty()) return s;

        int n1 = s.size(), n2 = t.size();
        vector<int> vec1;
        vector<int> vec2;

        // 存放各位的值(从后往前)
        for (int i = n1 - 1; i >= 0; i--) vec1.push_back(s[i] - '0');// char转int(-'0')
        for (int i = n2 - 1; i >= 0; i--) vec2.push_back(t[i] - '0');

        int n = min(n1, n2);
        int i = 0;

        vector<int> sum;// 存放和的各位的值(int类型)
        int add = 0;// 进位值
        // 从地位到高位存放
        while (i < n) {
            int cur = (vec1[i] + vec2[i] + add) % 10;
            add = (vec1[i] + vec2[i] + add) / 10;
            sum.push_back(cur);
            i++;
        }

        if (n1 > n) {
            while (i < n1) {
                int cur = (vec1[i] + add) % 10;
                add = (vec1[i] + add) / 10;
                sum.push_back(cur);
                i++;
            }
        }

        if (n2 > n) {
            while (i < n2) {
                int cur = (vec2[i] + add) % 10;
                add = (vec2[i] + add) / 10;
                sum.push_back(cur);
                i++;
            }
        }

        // 最高位仍然有进位
        if (add > 0) sum.push_back(add);

        // sum倒序-->高位到低位
        reverse(sum.begin(), sum.end());
        string ans = "";
        for (auto& x : sum) ans.push_back(x + '0');// int转char(+'0')

        return ans;
    }
};