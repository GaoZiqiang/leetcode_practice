/* leetcode T222:完全二叉树的节点个数
 * 原题链接：https://leetcode-cn.com/problems/count-complete-tree-nodes/
 * */

/* 方法：二分查找+位运算
 *
 * 算法思想：
 * 参考：https://leetcode-cn.com/problems/count-complete-tree-nodes/solution/wan-quan-er-cha-shu-de-jie-dian-ge-shu-by-leetco-2/
 *
 * 复杂度分析：
 * 时间复杂度：O(logn * logn)，二分查找和exists()函数都为logn。
 * 空间复杂度：O(1)。
 * */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
bool exists(TreeNode* root, int level, int k) {
    int bits = 1 << (level - 1);
    TreeNode* node = root;
    while (node != nullptr && bits > 0) {
        if (!(bits & k)) {// 第几个高位为0-->左转
            node = node->left;
        } else {// 1-->右转
            node = node->right;
        }
        bits >>= 1;// 右移一位-->测试下一个高位置
    }
    return node != nullptr;
}
int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    // 计算树的高度h
    int level = 0;
    TreeNode* tmp = root;
    while (tmp->left != nullptr) {
        level++;
        tmp = tmp->left;
    }
    // 计算节点总数的范围
    int low = 1 << level, high = (1 << (level + 1)) - 1;
    while (low < high) {
        int mid = (high - low + 1) / 2 + low;
        // 判断节点是否存在
        if (exists(root, level, mid)) {// k存在
            low = mid;// 目标节点总数>=k
        } else {
            high = mid - 1;// 目标节点总数<k
        }
    }
    return low;
}