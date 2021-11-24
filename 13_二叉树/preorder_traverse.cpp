/* leetcode T144:二叉树的先序遍历
 * 原题链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 * */

#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>

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

/*先序遍历实现方式*/
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

/*测试*/
int main() {
    BiTree BT;

    /*创建树*/
    createBiTreePre(BT);
    /*先序遍历*/
    preorderTraverse(BT);
}
