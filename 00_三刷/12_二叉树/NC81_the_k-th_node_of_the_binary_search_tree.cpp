/* NC81 二叉搜索树的第k个节点
 * 原题链接：https://www.nowcoder.com/practice/57aa0bab91884a10b5136ca2c087f8ff?tpId=117&tqId=37783&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * */

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val_) : val(val_), left(nullptr), right(nullptr) {}
};

// 中序遍历
void inOrder(TreeNode* root, vector<int>& res) {
    if(!root) return;
    inOrder(root->left, res);
    res.push_back(root->val);
    inOrder(root->right, res);
}

int KthNode(TreeNode* proot, int k) {
    // write code here
    if (!proot) return -1;
    vector<int> res;
    inOrder(proot, res);
    if (k <=0 || k > res.size()) return -1;
    return res[k-1];
}

// 方法二
// 中序遍历
void inOrder(TreeNode* root, int& count, int k, int& res) {
    if(!root) return;
    inOrder(root->left, count, k, res);
    count++;
    if (count == k) {
        res = root->val;
        return;
    }
    inOrder(root->right, count, k, res);
}

int KthNode(TreeNode* proot, int k) {
    // write code here
    if (!proot) return -1;
    int count = 0, res = -1;
    inOrder(proot, count, k, res);
    if (k <=0) return -1;
    return res;
}