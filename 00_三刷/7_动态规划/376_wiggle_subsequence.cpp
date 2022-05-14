/* leetcode T376:摆动序列
 * 原题链接：https://leetcode.cn/problems/wiggle-subsequence/
 * */

/* 方法一：贪心
 *
 * 算法思想：参考https://www.programmercarl.com/0376.%E6%91%86%E5%8A%A8%E5%BA%8F%E5%88%97.html#%E6%80%9D%E8%B7%AF2-%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92
 * 找波峰波谷
 * 每一个波峰波谷都是待选元素
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个元素至多访问一次。
 * 空间复杂度：O(1)。
 *
 * 方法二：动态规划
 *
 * 算法思想：
 * 考虑用动态规划的思想来解决这个问题。
 * 很容易可以发现，对于我们当前考虑的这个数，要么是作为山峰（即nums[i] > nums[i-1]），要么是作为山谷（即nums[i] < nums[i - 1]）。
 * 设dp状态dp[i][0]，表示考虑前i个数，第i个数作为山峰的摆动子序列的最长长
 * 设dp状态dp[i][1]，表示考虑前i个数，第i个数作为山谷的摆动子序列的最长长度
 * 则转移方程为：
 * dp[i][0] = max(dp[i][0], dp[j][1] + 1)，其中0 < j < i且nums[j] < nums[i]，表示将nums[i]接到前面某个山谷后面，作为山峰。
 * dp[i][1] = max(dp[i][1], dp[j][0] + 1)，其中0 < j < i且nums[j] > nums[i]，表示将nums[i]接到前面某个山峰后面，作为山谷。
 * 初始状态：
 * 由于一个数可以接到前面的某个数后面，也可以以自身为子序列的起点，所以初始状态为：dp[0][0] = dp[0][1] = 1。
 *
 * 复杂度分析：
 * 时间复杂度：
 * 空间复杂度：
 * */

#include <vector>

using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n;

    int curDiff = 0, preDiff = 0;
    int ans = 1;

    for (int i = 0; i < n-1; i++) {
        curDiff = nums[i+1] - nums[i];
        if ((curDiff < 0 && preDiff >= 0) || (curDiff > 0 && preDiff <= 0)) {
            ans++;
            preDiff = curDiff;
        }
    }

    return ans;
}

// 方法二：动态规划
// O(n*n) O(n*n)
int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(1005, vector<int>(2));
    dp[0][0] = 1, dp[0][1] = 1;

    for (int i = 1; i < n; i++) {
        dp[i][0] = 1, dp[i][1] = 1;

        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
        }

        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
        }
    }

    return max(dp[n-1][0], dp[n-1][1]);
}

// 方法二：动态规划
// O(n) O(n)
int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return n;
    vector<int> up(n), down(n);// up[i]:第i个元素为波峰/波谷时的最长子序列长度
    up[0] = 1, down[0] = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i-1]) {
            up[i] = max(up[i-1], down[i-1] + 1);// 元素i-1作为波峰，或元素i-1最为波谷，元素i作为波峰
            down[i] = down[i-1];// 此时元素i不可能成为波谷了，只能用down[i-1]赋值--只可能元素i-1作波谷
        } else if (nums[i] < nums[i-1]) {
            up[i] = up[i-1];
            down[i] = max(down[i-1], up[i-1] + 1);
        } else {
            up[i] = up[i-1];
            down[i] = down[i-1];
        }
    }

    return max(up[n-1], down[n-1]);
}