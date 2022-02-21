/* leetcode T112:路径总和
 * 原题链接：https://leetcode-cn.com/problems/path-sum/
 * */

/* 方法一：基于回溯法
 *
 * 算法思想：
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，所有节点遍历一遍。
 * 空间复杂度：O(n)，递归所需空间。
 * */

// 解决方法
bool backTracking(TreeNode* root, int pathSum, int targetSum) {
    // 终止条件
    if (!root->left && !root->right && pathSum == targetSum) return true;
    if (!root->left && !root->right) return false;

    // 横向单层循环
    if (root->left) {
        pathSum += root->left->val;
        // 纵向递归
        if (backTracking(root->left, pathSum, targetSum)) return true;
        // 回溯
        pathSum -= root->left->val;
    }

    if (root->right) {
        pathSum += root->right->val;
        // 纵向递归
        if (backTracking(root->right, pathSum, targetSum)) return true;
        // 回溯
        pathSum -= root->right->val;
    }
    return false;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }
    int pathSum = root->val;// pathSum的初值为root->val
    return backTracking(root, pathSum, targetSum);
}

// 下面是我的方法--不work...
//bool backTracking(TreeNode* root, int pathSum, int targetSum) {
//    // 终止条件
//    path.push_back(root->val);
//    pathSum += root->val;
//    if (!root->left && !root->right) {
//        if (pathSum == targetSum) {
//            return true;
//        } else {
////            pathSum -= root->val;
//            return false;
//        }
//    }
//
//    backTracking(root->left, pathSum, targetSum);
//    backTracking(root->right, pathSum, targetSum);
//    return false;
//}
//
//
//bool hasPathSum(TreeNode* root, int targetSum) {
//    if (!root) {
//        return false;
//    }
//    int pathSum = 0;
//    return backTracking(root, pathSum, targetSum)
//}