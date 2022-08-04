/* BM66 最长公共子串
 * 原题链接：https://www.nowcoder.com/practice/f33f5adc55f444baa0e0ca87ad8a6aac?tpId=295&tqId=991150&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 * 算法思想：
 * 动态规划dp
 * /

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int n1 = str1.size(), n2 = str2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        int maxsize = 0;
        int finalpos = 0;

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                if (dp[i][j] > maxsize) {
                    maxsize = dp[i][j];
                    finalpos = i - 1;
                }
            }
        }

        return str1.substr(finalpos - maxsize + 1, maxsize);
    }
};