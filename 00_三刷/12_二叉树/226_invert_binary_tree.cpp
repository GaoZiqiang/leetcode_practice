/* leetcode T226:翻转二叉树
 * 原题链接：https://leetcode-cn.com/problems/invert-binary-tree/
 * */

#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>

/*两种宏?定义方式*/
#define ELEM_TYPE int
//typedef char ELEM_TYPE;
using namespace std;

/* 方法一：基于递归
 * 核心思想：
 * 两个子树两两交换
 *
 * 两种方法：自顶向下和自下往上
 *
 * 复杂度分析：
 * 时间复杂度：O(n) n是给定的树的全部节点，我们最多访问每个节点一次；
 * 空间复杂度：O(n) 递归需要辅助栈空间，大小为节点个数n。
 * */

// 解法
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

/*存储结构*/
typedef struct TreeNode {
    ELEM_TYPE data;
    struct TreeNode *lchild, *rchild;
}BiTNode;

/*声明树的根节点（的地址）*/
typedef TreeNode *BiTree;// 创建首指针 一个地址/指针而已

/*按照先序遍历的顺序创建树*/
void createBiTreePre(BiTree &BT) {// 使用引用，不会改变原数组的地址，在原数组的基础上进行修改
    ELEM_TYPE ch;
    cout << "请输入节点数值:" << endl;
    cin >> ch;// 这里输入的字符会转换成ASSIC码

    /*创建左右子树*/
    if (ch == 0)// 叶子节点后为0
        BT = NULL;
    else {
        BT = new BiTNode;// 创建新节点
        BT->data = ch;
        /*递归调用*/
        createBiTreePre(BT->lchild);// 先把左子树创建完
        createBiTreePre(BT->rchild);// 再创建右子树
    }

    // return BT;// 使用引用形参，就不用返回创建好的树，而使用指针作为形参则需要进行返回值，返回创建好的那棵树
}