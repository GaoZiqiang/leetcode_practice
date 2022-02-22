/* leetcode T110:平衡二叉树
 * 原题链接：https://leetcode-cn.com/problems/balanced-binary-tree/
 * */

/* 方法：深度优先递归
 *
 * 算法思想：
 * 判断左叶子的条件：
 * if (root->left && !root->left->left && !root->left->right) {
 *      sum += root->left->val;
 *  }
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个节点都遍历一遍。
 * 空间复杂度：O(logn)，递归的层数。
 * */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 求和
void dfs(TreeNode* root, int& sum) {
    // 终止条件
    if (!root) {
        return;
    }
    // 左叶子
    if (root->left && !root->left->left && !root->left->right) {
        sum += root->left->val;
    }
    dfs(root->left, sum);
    dfs(root->right, sum);
    return;
}

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int sum = 0;
    dfs(root, sum);
    return sum;
}