/* leetcode T111:二叉树的最小深度
 * 原题链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 * */

/* 方法：递归+回溯
 *
 * 算法思想：
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个节点遍历一遍。
 * 空间复杂度：O(logn)，递归，高度为logn。
 * */


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 回溯
void backTracking(TreeNode* root, int& depth, int& level) {
    // 终止条件
    if (!root->left && !root->right) {
        depth = min(depth, level);
        return;
    }
    // 横向--单层循环
    if (root->left) {
        level++;
        backTracking(root->left, depth, level);
        level--;
    }
    // 纵向--递归
    if (root->right) {
        level++;
        backTracking(root->right, depth, level);
        level--;
    }
    return;
}

int minDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int level = 1, depth = INT_MAX;// level初值为1
    backTracking(root, depth, level);
    return depth;
}