/* leetcode T105:从前序与中序遍历序列构造二叉树
 * 原题链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * */

#include <vector>
#include <unordered_map>
#include <stack>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>

/*两种宏?定义方式*/
#define ELEM_TYPE int
//typedef char ELEM_TYPE;
using namespace std;

/* 方法一：基于层次遍历与回文数判别
 * 核心思想：
 * 找到每棵子树的根节点，然后在中序遍历序列中确定该根节点对应的左右子树节点（群），然后分别确定左右子树节点群在
 * 前序序列和中序序列中的左右边界
 * 如此递归下去
 * 关键：
 * 找到每棵子树的根节点，确定左右子树在两个序列中的边界/范围
 *
 * 复杂度分析：
 * 时间复杂度：O(n) 树中节点个数；
 * 空间复杂度：O(n) 包含三部分：hash map--O(n)，递归栈空间O(h)，存储建成的树--O(n)。
 * */

/*存储结构*/
typedef struct TreeNode {
    ELEM_TYPE data;
    struct TreeNode *lchild, *rchild;
}BiTNode;

/*声明树的根节点（的地址）*/
typedef TreeNode *BiTree;// 创建首指针 一个地址/指针而已

/*先序遍历--用于查看建成的树*/
vector<ELEM_TYPE> preorderTraverse(BiTree &root) {
    /*保存遍历结果*/
    vector<ELEM_TYPE> res;
    /*初始化辅助栈*/
    stack <BiTNode *> s;// s是一个指针，是一个地址

    /*根节点入栈*/
    s.push(root);

    while(!s.empty()) {
        /*1 获取栈顶节点并出栈*/
        auto node = s.top();
        res.push_back(node->data);
        cout << "visited node:" << node->data << endl;
        /*退出栈顶元素*/
        s.pop();
        /*2 左右子树入栈*/
        if (node->rchild)
            /*先右子树*/
            s.push(node->rchild);
        if (node->lchild)
            /*再左子树*/
            s.push(node->lchild);
    }

    return res;
}

/*辅助函数*/
BiTNode* subBuildTree(unordered_map<int, int> hash, const vector<int>& preorder, const vector<int>& inorder,
                      int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
    if (preorder_left > preorder_right)
        return nullptr;

    // 确定根节点在前序序列和后序序列中的位置
    int preorder_root = preorder_left;// 前序遍历第一个节点就是根节点
    int inorder_root = hash[preorder[preorder_root]];// 找到前序遍历中根节点在中序遍历序列中的位置

    // 构建根节点
    BiTNode* root = new BiTNode;
    root->data = preorder[preorder_root];
    // 左子数中节点数量
    int num_left_subtree = inorder_root - inorder_left;
    // 递归构造左子树
    // 关键：确定左右子树在前中序序列的起始边界
    // 前序序列的边界：[preorder_left + 1, preorder_left + 1 + num_left_subtree - 1] <==> [preorder_left + 1, preorder_left + num_left_subtree]
    // 中序序列的边界：[inorder_left, inorder_root - 1]
    root->lchild = subBuildTree(hash, preorder, inorder, preorder_left + 1, preorder_left + num_left_subtree, inorder_left, inorder_root - 1);
    // 递归构造右子树
    // 关键：确定左右子树在前中序序列的起始边界
    // 前序序列的边界：[preorder_left + num_left_subtree + 1, preorder_right]
    // 中序序列的边界：[inorder_root + 1, inorder_right]
    root->rchild = subBuildTree(hash, preorder, inorder, preorder_left + num_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);

    return root;
}

// 实现方法
BiTNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    int order_len = preorder.size();
    // 构建hash map,存储inorder中元素的索引序号
    unordered_map<int, int> hash;
    for (int i = 0; i < order_len; ++i) {
//        hash[inorder[i]] = i;
        hash.insert({inorder[i], i});// 插入方式二
    }

    return subBuildTree(hash, preorder, inorder, 0, order_len -1, 0, order_len - 1);
}

/*测试*/
int main() {
    BiTree BT;
    vector<int> preorder = {4,9,20,15,7};
    vector<int> inorder = {9,4,15,20,7};
    BiTree root = buildTree(preorder, inorder);
    // 遍历测试
    preorderTraverse(root);
    return 0;
}