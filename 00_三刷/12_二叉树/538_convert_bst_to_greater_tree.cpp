/* leetcode T538:把二叉搜索树转换为累加树
 * 原题链接：https://leetcode.cn/problems/convert-bst-to-greater-tree/
 * */

/* 方法一：反中序遍历
 *
 * 算法思想：
 * 本题中要求我们将每个节点的值修改为原来的节点值加上所有大于它的节点值之和。这样我们只需要反序中序遍历
 * 该二叉搜索树，记录过程中的节点值之和，并不断更新当前遍历到的节点的节点值，即可得到题目要求的累加树。
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，遍历完一遍即可。
 * 空间复杂度：O(n)，递归层数，平均为O(logn)，因为是二叉排序树，最坏情况为O(n)--链式。
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

// 方法一：先求中序序列 然后计算各节点的后续和 然后更新节点值
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
    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) return;

        dfs(root->left, res);
        res.push_back(root->val);
        dfs(root->right, res);

        return;
    }

    void update(TreeNode* root, unordered_map<int, int>& map) {
        if (!root) return;

        root->val = map[root->val];
        update(root->left, map);
        update(root->right, map);

        return;
    }

    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;

        vector<int> node_values;
        dfs(root, node_values);

        unordered_map<int, int> map;
        for (int i = 0; i < node_values.size(); i++) {
            int node_value = node_values[i];
            int node_sum = 0;
            for (int j = i; j < node_values.size(); j++) {
                node_sum += node_values[j];
            }
            map[node_value] = node_sum;
        }

        update(root, map);

        return root;
    }
};

// 方法二：反序中序遍历
class Solution {
public:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;

        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);

        return root;
    }
};