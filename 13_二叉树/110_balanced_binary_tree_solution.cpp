/* leetcode T110:平衡二叉树
 * 原题链接：https://leetcode-cn.com/problems/balanced-binary-tree/solution/
 * */

#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>

/* 方法一：递归--基于求树的高度算法
 *
 * 判断左右两棵子树的高度差，若任意一棵子树高度差大于1则不是平衡二叉树。
 *
 * 复杂度分析：
 * 时间复杂度：平均O(nlogn)，最差O(n^2)--二叉树为一个长链
 * 空间复杂度：O(n)，取决于递归调用的次数，不会超过节点数n。
 * */

/*两种宏?定义方式*/
#define ELEM_TYPE char
//typedef char ELEM_TYPE;
using namespace std;

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
    if (ch == '0')// 叶子节点后为'0'--输入'0'表示节点结束，没有子节点 切记：此处ch值类型为char
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

int helper(BiTree &root) {
    if (!root)
        return 0;

    int left = helper(root->lchild), right = helper(root->rchild);

    // left == -1 || right == -1表示该子树为不平衡的子树,此时便可以退出算法判断--避免子树不平衡后还要继续回溯其父辈节点--节省成本
    if (left == -1 || right == -1 || abs(left - right) > 1)
        return -1;

    return 1 + max(left, right);
}

bool isBalanced(BiTree &root) {
    return helper(root) != -1;
}

int main() {
    BiTree BT;

    /*创建二叉树*/
    createBiTreePre(BT);

    if (isBalanced(BT))
        cout << "isBalanced" << endl;
    else
        cout << "notBalanced" << endl;

}
