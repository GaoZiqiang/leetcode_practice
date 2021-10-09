/* leetcode T104:二叉树的最大深度
 * 原题链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 * */

#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>

/* 方法一：基于层次遍历--广度优先遍历
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个节点遍历一次。
 * 空间复杂度：O(1)，不需要额外空间。
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

int maxDepth(BiTree &root) {
    queue<BiTNode *> queue;
    queue.push(root);

    int depth = 0;

    while (!queue.empty()) {
        int queue_sz = queue.size();
        while (queue_sz > 0) {
            BiTNode * tmp_node = queue.front(); queue.pop();
            if (tmp_node->lchild)
                queue.push(tmp_node->lchild);
            if (tmp_node->rchild)
                queue.push(tmp_node->rchild);
            queue_sz -= 1;
        }
        depth += 1;
    }

    return depth;
}

/*测试*/
int main() {
    BiTree BT;

    /*创建二叉树*/
    createBiTreePre(BT);

    printf("depth: %d\n", maxDepth(BT));
}
