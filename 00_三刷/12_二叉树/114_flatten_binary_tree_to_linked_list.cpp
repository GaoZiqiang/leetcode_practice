/* leetcode T114:二叉树展开为链表
 * 原题链接：https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
 * */

/* 方法一：前序遍历+构造链表
 *
 * 算法思想：
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，所有节点遍历一遍。
 * 空间复杂度：O(n)，递归所需空间。
 * */

// 解法一
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
public:
    // 得到前序遍历序列
    void preTraverse(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;

        nodes.push_back(root);
        preTraverse(root->left, nodes);
        preTraverse(root->right, nodes);

        return;
    }

    void flatten(TreeNode* root) {
        if (!root) return;

        vector<TreeNode*> nodes;
        preTraverse(root,nodes );
        int n = nodes.size();

        // 修改各节点左右指针指向
        for (int i = 1; i < n; i++) {
            TreeNode* pre = nodes[i-1];
            TreeNode* cur = nodes[i];
            pre->right = cur;
            pre->left = nullptr;
        }

        // 最后一个节点
        nodes[n-1]->left = nullptr;
        nodes[n-1]->right = nullptr;

        return;
    }
};

// 解法二
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
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> stack;

        // 根节点入栈
        stack.push(root);
        TreeNode* pre = nullptr;

        while (!stack.empty()) {
            TreeNode* cur = stack.top();
            stack.pop();

            // 修改左右指针指向
            if (pre != nullptr) {
                pre->right = cur;
                pre->left = nullptr;
            }

            TreeNode* left = cur->left;
            TreeNode* right = cur->right;

            // 右子树先进栈/后出栈
            if (right != nullptr) stack.push(right);
            if (left != nullptr) stack.push(left);

            // 更新pre
            pre = cur;
        }

        return;
    }
};