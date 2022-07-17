/* NC62 判断是不是平衡二叉树
 * 原题链接：https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=117&tqId=37757&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * */


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val_) : val(val_), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 求子树的高度
    int height(TreeNode* root) {
        if (!root) return 0;
        int left = 1 + height(root->left);
        int right = 1 + height(root->right);
        return max(left, right);
    }

    // 判断是否平衡
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) return true;

        // 先主节点
        int lefth = height(pRoot->left);
        int righth = height(pRoot->right);
        if (abs(lefth - righth) > 1) return false;

        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};