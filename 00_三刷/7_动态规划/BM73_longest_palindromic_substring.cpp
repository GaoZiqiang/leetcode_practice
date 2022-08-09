/* BM73 最长回文子串
 * 原题链接：https://www.nowcoder.com/practice/b4525d1d84934cf280439aeecc36f4af?tpId=295&tqId=25269&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295
 * 算法思想：
 * 一：中心扩散
 * 二：动态规划dp
 * /

// 方法一：中心扩散
 class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A string字符串
     * @return int整型
     */
int helper(string& A, int left, int right) {
    while (left >= 0 && right < A.size()) {
        if (A[left] != A[right]) break;
        left--;
        right++;
    }
    return right - left - 1;// right - left + 1 - 2
}

int getLongestPalindrome(string A) {
    // write code here
    int n = A.size();

    int ans = -1;

    for (int i = 0; i < n; i++) {
        int len = helper(A, i, i) > helper(A, i, i+1) ? helper(A, i, i) : helper(A, i, i+1);
        ans = max(ans, len);
    }

    return ans;
}
};

// 方法二：动态规划
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A string字符串
     * @return int整型
     */
    int helper(string& A, int left, int right) {
        while (left >= 0 && right < A.size()) {
            if (A[left] != A[right]) break;
            left--;
            right++;
        }
        return right - left - 1;// right - left + 1 - 2
    }

    int getLongestPalindrome(string A) {
        int n = A.size();

        vector<vector<bool>>  dp(n, vector<bool>(n, false));
        int ans = -1;

        for (int len = 0; len <= n+1; len++) {
            for (int left = 0; left + len < n; left++) {// 统计以left为起点，长度为len的子串[left, right]是否为回文串
                int right = left + len;

                if (A[left] == A[right]) {
                    if (len <= 1) dp[left][right] = true;
                    else {
                        dp[left][right] = dp[left+1][right-1];// 取决于中间元素
                    }
                    if (dp[left][right]) ans = len + 1;
                }
            }
        }

        return ans;
    }
};