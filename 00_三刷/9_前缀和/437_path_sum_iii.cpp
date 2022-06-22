/* leetcode T437:路径总和III
 * 原题链接：https://leetcode-cn.com/problems/path-sum-iii/
 * */

/* 方法一：基于深度优先遍历+前缀和
 * 算法思想：
 * 参考：https://leetcode-cn.com/problems/path-sum-iii/solution/lu-jing-zong-he-iii-by-leetcode-solution-z9td/
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个节点只需要遍历一次。
 * 空间复杂度：O(n)，递归-栈空间
 * */

#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {};
};

class Solution {
public:
    unordered_map<int, int> prefix;

    int dfs(TreeNode* root, long long  pathSum, int targetSum) {
        if (!root)
            return 0;

        int res = 0;

        pathSum += root->val;
        if (prefix.find(pathSum - targetSum) != prefix.end())
            res += prefix[pathSum - targetSum];

        prefix[pathSum]++;
        res += dfs(root->left, pathSum, targetSum);
        res += dfs(root->right, pathSum, targetSum);
        prefix[pathSum]--;

        return res;
    }


    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        long long  pathSum = 0;
        return dfs(root, pathSum, targetSum);
    }
};

// 我的解法
void dfs(TreeNode* root, int& count, int targetSum, long long& preSum, unordered_map<long long, int>& preSums) {
    if (!root) return;

    preSum += root->val;

    if (preSums.count(preSum - targetSum)) {
        count += preSums[preSum - targetSum];
    }

    preSums[preSum]++;

    // 左右子树
    dfs(root->left, count, targetSum, preSum, preSums);
    dfs(root->right, count, targetSum, preSum, preSums);

    // 该条路径结束--左右孩子都到头了
    preSums[preSum]--;// 一定要--
    preSum -= root->val;

    return;
}

int pathSum(TreeNode* root, int targetSum) {
    int ans = 0;
    long long preSum = 0;
    unordered_map<long long, int> preSums;
    preSums[0] = 1;

    dfs(root, ans, targetSum, preSum, preSums);

    return ans;
}
