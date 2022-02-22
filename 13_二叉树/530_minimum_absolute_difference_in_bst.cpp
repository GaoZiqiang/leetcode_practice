/* leetcode T530:二叉搜索树的最小绝对差
 * 原题链接：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
 * */

/* 方法一：基于中序遍历
 *
 * 算法思想：
 * 由二叉搜索树中序遍历序列为单调递增序列的特性，我们知道差值最小的两个值一定是相邻的值
 * 因此我们借助中序遍历序列，找到差值最小的两个相邻节点值。
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，遍历完一遍即可。
 * 空间复杂度：O(logn)，递归。
 * */

void inorder(TreeNode* root, int& pre, int& dif) {
    if (!root) {
        return;
    }
    // 左子树
    inorder(root->left, pre, dif);
    // 根节点的判断逻辑
    if (pre == -1) {
        pre = root->val;// 二叉搜索树中序遍历序列的第一个节点
    } else {
        dif = min(root->val - pre, dif);
        pre = root->val;
    }
    // 右子树
    inorder(root->right, pre, dif);
    return;
}
int getMinimumDifference(TreeNode* root) {
    int pre = -1, dif = INT_MAX;
    inorder(root,pre,  dif);
    return dif;
}