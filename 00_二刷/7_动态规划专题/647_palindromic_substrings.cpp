/* T647:回文子串 https://leetcode-cn.com/problems/palindromic-substrings/
 * 思想：
 * dp[i][j]表示[i,j]区间的子串是否为回文串
 * 分为三种情况:1 2 3
 * 注意遍历顺序，因为情况三dp[i][j]依赖于dp[i+1][j-1]-->考虑从下往上，从左到右的顺序遍历
 * 方法：动态规划O(n*n)
 * */

int countSubstrings(string s) {
    int n = s.size();
    int ans = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0 ;i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j]) {
                if (j - i <= 1) {// 情况一：i == j 情况二：i与j相差1
                    ans++;
                    dp[i][j] = true;
                } else if (dp[i+1][j-1]) {// 情况三：i与j相差2个以上元素-->此时需要根据s[i+1]和s[j-1]进行判断
                    ans++;
                    dp[i][j] = true;
                }
            }
        }
    }
    return ans;
}