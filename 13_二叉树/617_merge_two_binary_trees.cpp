/* leetcode T617:合并二叉树
 * 原题链接：https://leetcode-cn.com/problems/merge-two-binary-trees/
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
 * 两个结点都存在-->root = root1->data + root2->data
 * 有一个不存在-->root直接指向存在的结点
 *
 * 复杂度分析：
 * 时间复杂度：O(min(m,n)) m,n分别是给定的两棵树的全部节点，我们最多访问每个节点一次；
 * 空间复杂度：O(min(m,n)) 递归需要辅助栈空间，大小为节点个数。
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
BiTNode* mergeTrees(BiTree& root1, BiTree& root2) {
    // 两个子树结点有不存在情况
//    if (!root1 && !root2)
//        return nullptr;
//    if ((root1 && !root2) || (!root1 && root2))
//        return root1 ? root1 : root2;
    if (!root1)
        return root2;
    if (!root2)
        return root1;

    // 两个子树结点都存在
    // 先解决根节点
    BiTNode* root = new BiTNode;// 创建结点
    root->data = root1->data + root2->data;
    // 再解决子树
    root->lchild = mergeTrees(root1->lchild, root2->lchild);
    root->rchild = mergeTrees(root1->rchild, root2->rchild);

    return root;
}

/*测试*/
int main() {
    BiTree BT1, BT2;
    /*创建二叉树*/
    cout << "创建BT1" << endl;
    createBiTreePre(BT1);
    cout << "创建BT2" << endl;
    createBiTreePre(BT2);
    BiTNode* res = mergeTrees(BT1, BT2);
    preorderTraverse(res);
    return 0;
}