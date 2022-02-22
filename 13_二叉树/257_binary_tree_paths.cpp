/* leetcode T257:二叉树的所有路径
 * 原题链接：https://leetcode-cn.com/problems/binary-tree-paths/
 * */

/* 方法：递归+回溯
 *
 * 算法思想：
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个节点都要遍历一遍。
 * 空间复杂度：O(logn)，递归的层数。
 * */

#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void backTracking(TreeNode* root, string& path, vector<string>& res) {
    // 终止条件
    if (!root->left && !root->right) {
        res.push_back(path);
        return;
    }
    // 横向--单层循环
    if (root->left) {
        path += "-";
        path += ">";
        path += to_string(root->left->val);
        backTracking(root->left, path, res);
        path.pop_back();
        path.pop_back();
        path.pop_back();
    }
    // 纵向--递归
    if (root->right) {
        path += "-";
        path += ">";
        path += to_string(root->right->val);
        backTracking(root->right, path, res);
        path.pop_back();
        path.pop_back();
        path.pop_back();
    }
    return;
}

vector<string> binaryTreePaths(TreeNode* root) {
    if (!root) {
        return {};
    }
    vector<string> res;
    string path;
    path += to_string(root->val);
    backTracking(root, path, res);
    return res;
}
