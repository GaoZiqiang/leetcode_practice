/* leetcode T236:二叉树的最近公共祖先
 * 原题链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * */

/* 方法一：存储父节点
 *
 * 算法思想：
 * 1 遍历二叉树，使用哈希map找到每个节点的父节点；
 * 2 依次访问p的父节点，并将访问过的父节点做访问标记；
 * 3 然后再依次访问q的父节点，若访问到被p访问过的第一个父节点，则返回，该节点即最近的公共祖先节点。
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个数字包含的位数。
 * 空间复杂度：O(n)，searchFather递归使用栈空间；fathers和visited两个unordered_map。
 * */

unordered_map<int, TreeNode*> fathers;
unordered_map<int, bool> visited;
void searchFather(TreeNode* root) {
    if (!root) {
        return;
    }
    if (root->left){// 需要先对左右子树是否存在进行判断
        fathers[root->left->val] = root;
    }
    if (root->right) {
        fathers[root->right->val] = root;
    }
    searchFather(root->left);
    searchFather(root->right);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 统计每个节点的父节点
    fathers[root->val] = nullptr;
    searchFather(root);

    // 遍历p的父节点
    while (p) {
        visited[p->val] = true;
        p = fathers[p->val];
    }

    // 遍历q的父节点
    while (q) {
        // 返回最近的公共祖先节点
        if (visited[q->val]) {
            return q;
        }
        q = fathers[q->val];
    }
    return nullptr;
}

class Solution {
public:
    // 这里使用unordered_map存储，可以解决vector不好初始化的问题
    unordered_map<int, TreeNode*> fathers;
    unordered_map<int, bool> visited;

public:
    void searchFather(TreeNode* root) {
        if (!root) return;

        // 保存每个节点的父节点--从下往上保存
        if (root->left) {
            fathers[root->left->val] = root;
        }

        if (root->right) {
            fathers[root->right->val] = root;
        }

        searchFather(root->left);
        searchFather(root->right);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 初始化fathers
        fathers[root->val] = NULL;
        searchFather(root);

        // 从下往上遍历fathers"数组"
        while (p) {
            visited[p->val] = true;// 访问标记置true
            p = fathers[p->val];
        }

        while (q) {
            if (visited[q->val]) return q;
            q = fathers[q->val];
        }

        return NULL;
    }
};