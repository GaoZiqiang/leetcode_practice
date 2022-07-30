/* BM84 最长公共前缀
 * 原题链接：https://www.nowcoder.com/practice/28eb3175488f4434a4a6207f6f484f47?tpId=295&tqId=732&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 * */

class Solution {
public:
    /**
     *
     * @param strs string字符串vector
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        // write code here
        int n = strs.size();
        if (n == 0) return "";

        for (int i = 0; i < strs[0].size(); i++) {
            // 截取第一个字符串
            char tmp = strs[0][i];
            // 比较后续字符串
            for (int j = 1; j < n; j++) {
                // strs[j]结束或strs[j][i]与strs[0][i]不相等                                                                                ]
                if (strs[j].size() == i || strs[j][i] != tmp) {
                    return strs[0].substr(0, i);// 截取前i个作为前缀
                }
            }
        }
        return strs[0];
    }
};