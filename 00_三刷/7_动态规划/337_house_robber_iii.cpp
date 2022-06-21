/* leetcode T337:打家劫舍III
 * 原题链接：https://leetcode.cn/problems/house-robber-iii/
 * */

/* 方法一：动态规划--基于递归
 *
 * 算法思想：参考https://programmercarl.com/0337.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8DIII.html#%E6%80%9D%E8%B7%AF
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，遍历完一遍即可。
 * 空间复杂度：O(n)，vector<int> dp。
 *
 * */


#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}

// 后序递归+dp
vector<int> robTree(TreeNode* root) {
    if (!root) return vector<int>{0, 0};

    // 左右子树
    vector<int> left = robTree(root->left);
    vector<int> right = robTree(root->right);

    // 当前节点
    // 偷当前节点
    int val1 = root->val + left[0] + right[0];// 0:不偷 1:偷

    // 不偷当前节点
    int val2 = max(left[0], left[1]) + max(right[0], right[1]);

    return {val2, val1};// 注意这里只保存偷和不偷的对应状态值 不做判断-->因为返回值类型为数组
}

int rob(TreeNode* root) {
    vector<int> res = robTree(root);

    return max(res[0], res[1]);
}