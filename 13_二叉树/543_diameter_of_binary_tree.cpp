/* leetcode T543:二叉树的直径
 * 原题链接：https://leetcode-cn.com/problems/diameter-of-binary-tree/
 * */

#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>

/* 方法一：基于深度优先遍历
 * 算法思想：
 * 一条路径长度=该路径经过的节点数减1-->求直径(求路径长度的最大值)==求路径经过节点数的最大值减1
 * 重要：任意一条路径均可以被看做由某个节点为起点，从其左儿子和右儿子向下遍历的路径拼接而得。
 *
 * 假设我们知道对于该节点的左儿子向下遍历经过最多的节点数 L（即以左儿子为根的子树的深度）
 * 和其右儿子向下遍历经过最多的节点数 R（即以右儿子为根的子树的深度），
 * 那么以该节点为起点的路径经过节点数的最大值即为 L+R+1。
 *
 * 我们记节点node为起点的路径经过节点数的最大值为d_node，那么二叉树的直径就是所有节点d_node的最大值减一。
 *
 * 最后的算法流程为：我们定义一个递归函数depth(node)计算d_node，函数返回该节点为根的子树的深度。
 * 先递归调用左儿子和右儿子求得它们为根的子树的深度 L和 R，则该节点为根的子树的深度即为
 * max(L,R) + 1
 * 该节点的d_node值为
 * L + R + 1
 *
 * 递归搜索每个节点并设一个全局变量ans记录d_node的最大值，最后返回ans-1即为树的直径。
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个节点遍历一次。
 * 空间复杂度：O(Height)，Height为二叉树的高度。由于递归函数在递归过程中需要为每一层递归函数分配栈空间，
 * 所以这里需要额外的空间且该空间取决于递归的深度，而递归的深度显然为二叉树的高度，并且每次递归调用
 * 的函数里又只用了常数个变量，所以所需空间复杂度为O(Height)。
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

int depth(BiTree &root, int& diameter) {
    if (!root)
        return 0;// 空节点,depth=0

    int l = depth(root->lchild, diameter);// 左子树深度
    int r = depth(root->rchild, diameter);// 右子树深度
    diameter = max(diameter, l + r + 1);// 更新最大路径长度--直径
    return max(l, r) + 1;// 返回该节点的深度--该节点的左右两棵子树的深度的最大值
}

int diameterOfBinaryTree(BiTree &root) {
    int ans = 0;
    depth(root, ans);
    return ans - 1;
}

/*测试*/
int main() {
    BiTree BT;

    /*创建二叉树*/
    createBiTreePre(BT);

    printf("depth: %d\n", diameterOfBinaryTree(BT));
}