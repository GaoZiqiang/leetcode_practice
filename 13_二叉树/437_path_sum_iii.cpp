/* leetcode T437:路径总和III
 * 原题链接：https://leetcode-cn.com/problems/path-sum-iii/
 * */

#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>

/* 方法一：基于深度优先遍历
 * 算法思想：
 * 参考：https://leetcode-cn.com/problems/path-sum-iii/solution/lu-jing-zong-he-iii-by-leetcode-solution-z9td/
 *
 * 复杂度分析：
 * 时间复杂度：O(n^2)，n为二叉树节点总数。对于每一个节点，求以该节点为起点的路径数目时，则需要遍历以该节点为
 * 根节点的子树的所有节点，因此求该路径所花费的最大时间为O(n)，我们会对每个节点都求一次以该节点为起点的路径数
 * 目，因此时间复杂度为O(n^2)。
 * 空间复杂度：O(n)，递归-栈空间
 * */

/*两种宏?定义方式*/
#define ELEM_TYPE int
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
    if (ch == 0)// 叶子节点后为int 0
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

// 辅函数
int pathSumStartWithRoot(BiTree& root, int sum) {
    if (!root)
        return 0;
    int count = root->data == sum ? 1 : 0;// 如果root->data == sum，表示找到一条从起点到该点的路径
    count += pathSumStartWithRoot(root->lchild, sum - root->data);
    count += pathSumStartWithRoot(root->rchild, sum - root->data);
    return count;
}

// 主函数
int pathSum(BiTree& root, int sum) {
    if (!root)
        return 0;
    int ret = pathSumStartWithRoot(root, sum);
    ret += pathSumStartWithRoot(root->lchild, sum);
    ret += pathSumStartWithRoot(root->rchild, sum);
    return ret;
}

/*测试*/
int main() {
    BiTree BT;

    /*创建二叉树*/
    createBiTreePre(BT);

    printf("path num: %d\n", pathSum(BT, 8));
}