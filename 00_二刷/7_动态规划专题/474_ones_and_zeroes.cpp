/* leetcode T474:一和零
 * 原题链接：https://leetcode-cn.com/problems/ones-and-zeroes/
 * */

/* 方法一：动态规划法
 *
 * dp五要素：
 * dp[i][j][k]：在数组nums的前i个数中选取元素，'0'的个数不超过j，'1'的个数不超过k的子集的长度；
 * dp初始化：全部为0；
 * 状态转移方程：c0、c1为每个字符串中'0'、'1'的个数
 * dp[i][j][k] = dp[i-1][j][k] j < c0 || k < c1--nums[i]一定不能加入
 *             = max(dp[i-1][j][k] + dp[i-1][j-c0][k-c1] + 1)--nums[i]可加入也可不加入
 *
 * 时间复杂度：O(n*m*n)；
 * 空间复杂度：O(n*m*n)：数组
 * */


int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();
    vector<vector<vector<int>>> dp(len+1, vector(m+1, vector(n+1, 0)));
    // dp初始化为0
    int ans = 0;
    for (int i = 1; i <= len; i++) {
        string str = strs[i-1];
        // 统计'0'和'1'的个数
        int c0 = 0, c1 = 0;
        for (auto& x : str) {
            if (x == '0')
                c0++;
            else
                c1++;
        }
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= n; k++) {
                if (j < c0 || k < c1) {// 不加入当前字符串
                    dp[i][j][k] = dp[i-1][j][k];
                } else {
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-c0][k-c1] + 1);
                }
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    return ans;
}