/* leetcode T047:二叉树剪枝
 * 原题链接：https://leetcode-cn.com/problems/pOCWxh/
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
 * 第一个关键点在于如何确定要剪掉的枝：root->data == 0 && !root->lchild && !root->rchild
 * 第二个关键点在于如何剪掉这个“枝”：只要将满足条件的要剪掉的枝的父结点的左或右指针指向nullptr即可
 * 第三个关键点在于以怎样的顺序“剪枝”：自下往上
 *
 * 复杂度分析：
 * 时间复杂度：O(n) n为树的结点总数；
 * 空间复杂度：O(n) 递归需要辅助栈空间大小为节点个数n。
 * */

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
    if (ch == 100)// 叶子节点后为0
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

// 解决方法
BiTNode* pruneTree(BiTree& root) {
    if (!root)
        return root;

    root->lchild = pruneTree(root->lchild);
    root->rchild = pruneTree(root->rchild);

    // 自下往上剪枝
    if (root->data == 0 && !root->lchild && !root->rchild)
        return nullptr;

    return root;
}

/*测试*/
int main() {
    BiTree BT;
    /*创建二叉树*/
    createBiTreePre(BT);

    BiTNode* res = pruneTree(BT);
    preorderTraverse(res);


    return 0;
}