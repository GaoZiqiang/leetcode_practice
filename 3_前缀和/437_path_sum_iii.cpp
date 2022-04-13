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
