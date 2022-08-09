/* NC138 矩阵最长递增路径 对比 BM68 矩阵的最小路径和
 * 原题链接：https://www.nowcoder.com/practice/7a71a88cdf294ce6bdf54c899be967a2?tpId=117&tqId=37850&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3D%25E7%259F%25A9%25E9%2598%25B5%25E6%259C%2580%25E9%2595%25BF%25E9%2580%2592%25E5%25A2%259E%25E8%25B7%25AF%25E5%25BE%2584%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=%E7%9F%A9%E9%98%B5%E6%9C%80%E9%95%BF%E9%80%92%E5%A2%9E%E8%B7%AF%E5%BE%84
 * 算法思想：
 * 动态规划dp
 * /

class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];

        dp[i][j]++;
        for (int k = 0; k < 4; k++) {
            int nexti = i + dirs[k][0];
            int nextj = j + dirs[k][1];

            if (nexti >= 0 && nexti < matrix.size() && nextj >= 0 && nextj < matrix[0].size() && matrix[nexti][nextj] > matrix[i][j]) {
                dp[i][j] = max(dp[i][j], dfs(matrix, dp, nexti, nextj) + 1);
            }
        }
        return dp[i][j];
    }

    int solve(vector<vector<int> >& matrix) {
        // write code here
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int ans = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, dp, i, j));
            }
        }

        return ans;
    }
};