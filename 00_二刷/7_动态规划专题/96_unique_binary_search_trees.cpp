/* T96:不同的二叉搜索树 https://leetcode-cn.com/problems/unique-binary-search-trees/
 * 思想：
 * 根据左右子树的节点数量不同判断可能的组合情况--
 * 对于节点总数为i时：若左边子树有a种，右边子树有b种-->一共有a*b中可能的组合
 * 方法：动态规划O(n*n)
 * */

int numTrees(int n) {
    vector<int> dp(n+1, 0);
    // 0和1个节点
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {// 节点总数为2 3 ... n时
        for (int j = 0; j < i; j++) {// 分情况讨论--左子树有j个节点时
            dp[i] += dp[j] * dp[i-1-j];// 左子树j 根节点1 右子树i-1-j
        }
    }
    return dp[n];
}