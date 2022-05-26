/* leetcode T968:监控二叉树
 * 原题链接：https://leetcode.cn/problems/binary-tree-cameras/
 * */

/* 方法一：贪心算法
 *
 * 算法思想：参考https://programmercarl.com/0968.%E7%9B%91%E6%8E%A7%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E6%80%9D%E8%B7%AF
 * 基于贪心，从叶子节点由下往上遍历
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，一次遍历。
 * 空间复杂度：O(n)，递归。
 * */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int ans;

public:
    // 状态定义：
    // 0 有覆盖
    // 1 放摄像头
    // 2 被覆盖
    int traverse(TreeNode* root) {
        // 空节点(叶子节点的孩子)-->返回2被覆盖
        if (root == nullptr) return 2;

        int left = traverse(root->left);
        int right = traverse(root->right);

        // 处理根节点
        // 情形1 左右孩子都被覆盖-->无覆盖0
        if (left == 2 && right == 2) {
            return 0;
        }

        // 情形2 左右孩子至少于一个无覆盖-->放摄像头1(ans++)
        if (left == 0 || right == 0) {
            ans++;
            return 1;
        }

        // 情形3 左右孩子至少一个有摄像头-->被覆盖2
        if (left == 1 || right == 1) {
            return 2;
        }
        // 情形4 树的根节点无覆盖-->加一个摄像头(主函数中设置)

        // 其他情形
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        ans = 0;

        // 树的根节点无覆盖-->加一个摄像头
        if (traverse(root) == 0) ans++;

        return ans;
    }
};