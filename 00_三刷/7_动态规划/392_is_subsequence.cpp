/* leetcode T392:判断子序列
 * 原题链接：https://leetcode.cn/problems/is-subsequence/
 * */

/* 方法一：双指针法
 *
 * 算法思想：
 * reset：
 * return origin_num即可
 * shuffle：
 * 直接调用vector的shuffle函数即可
 *
 * 复杂度分析：
 * 时间复杂度：O(n+m)，s.size()+t.size()。
 * 空间复杂度：O(1)。
 *
 * 方法二：基于动态规划
 *
 * 算法思想：
 * 使用数组预先存放母序列t中每个字符第一次出现的位置-->节省寻找t序列中下一个目标字符的时间
 *
 * */

// 方法一：双指针法
bool isSubsequence(string s, string t) {
    int n = s.size(), m = t.size();

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s[i] == t[j]) {
            i++, j++;
        } else {
            j++;
        }
    }

    return i == n;
}

// 方法二：动态规划（节省寻找t序列中下一个目标字符的时间）
bool isSubsequence(string s, string t) {
    int n = s.size(), m = t.size();

    vector<vector<int>> dp(m+1, vector<int>(26, 0));
    // 初始化dp[m][j]
    for (int i = 0; i < 26; i++) {
        dp[m][i] = m;
    }

    for (int i = m-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (t[i] == j + 'a') {
                dp[i][j] = i;
            } else {
                dp[i][j] = dp[i+1][j];
            }
        }
    }

    int add = 0;
    for (int i = 0; i < n; i++) {
        if (dp[add][s[i]-'a'] == m) return false;
        add = dp[add][s[i]-'a'] + 1;// 字符s[i]出现的位置 如果字符s[i]在母序列t中不存在，则dp[i][s[i]-'a']+1==m
    }

    return true;
}