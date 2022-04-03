/* T98:验证二叉搜索树 https://leetcode-cn.com/problems/validate-binary-search-tree/
 * 思想：
 * 根据二叉搜索树的性质，每个节点存在上下两个边界lower/upper
 * 每一个根节点root，其可以为左子树的上界upper，同时作为右子树的下界lower
 * 方法：动态规划O(n)
 * */

bool dfs(TreeNode* root, long lower, long upper) {
    if (root == nullptr)
        return true;
    if (root->val <= lower || root->val >= upper)
        return false;
    return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);// 更新上下界
}

bool isValidBST(TreeNode* root) {
    return dfs(root, LONG_MIN, LONG_MAX);
}