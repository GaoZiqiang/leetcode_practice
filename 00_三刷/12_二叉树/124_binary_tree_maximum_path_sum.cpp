/* leetcode T124:二叉树中的最大路径和
 * 原题链接：https://leetcode.cn/problems/binary-tree-maximum-path-sum/
 * */

/* 方法一：回溯法
 *
 * 算法思想：
 *  参考：https://leetcode.cn/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-leetcode-/
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，所有节点遍历一遍。
 * 空间复杂度：O(n)，递归所需空间。
 * */

int maxGain(TreeNode* root, int& maxSum) {
    if (!root) return 0;

    // 计算左右子树的贡献值
    int maxleft = maxGain(root->left, maxSum);
    // 贡献值小于0时，放弃
    if (maxleft < 0) maxleft = 0;
    int maxright = maxGain(root->right, maxSum);
    if (maxright < 0) maxright = 0;

    // 更新最大路径和
    maxSum = max(maxSum, root->val + maxleft + maxright);

    return root->val + max(maxleft, maxright);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxGain(root, maxSum);

    return maxSum;
}