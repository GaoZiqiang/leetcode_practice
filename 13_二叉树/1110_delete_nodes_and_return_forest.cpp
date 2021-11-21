/* leetcode T1110:删点成林
 * 原题链接：https://leetcode-cn.com/problems/delete-nodes-and-return-forest/
 * */

#include <vector>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <unordered_set>

/*两种宏?定义方式*/
#define ELEM_TYPE int
//typedef char ELEM_TYPE;
using namespace std;

/* 方法一：基于递归
 *
 * 复杂度分析：
 * 时间复杂度：O(n) 树中元素个数；
 * 空间复杂度：O(n+h) 需要一个长度为h的辅助队列，h为树的高度。
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

// 辅助函数
BiTNode* helper(BiTNode* root, unordered_set<int>& to_delete_set, vector<BiTNode*>& forest) {
    if (!root)
        return root;
    root->lchild = helper(root->lchild, to_delete_set, forest);
    root->rchild = helper(root->rchild, to_delete_set, forest);
    if (to_delete_set.count(root->data)) {
        if (root->lchild)
            forest.push_back(root->lchild);
        if (root->rchild)
            forest.push_back(root->rchild);
        root = nullptr;
    }
    return root;
}

// 主函数
vector<BiTNode*> delNodes(BiTree& root, vector<int>& to_delete) {
    vector<BiTNode*> forest;
    unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
    root = helper(root, to_delete_set, forest);
    if (root) {
        forest.push_back(root);
    }
    return forest;
}

/*测试*/
int main() {
    BiTree BT;
    /*创建二叉树*/
    createBiTreePre(BT);
    vector<int> to_delete = {1};
    vector<BiTNode*> res = delNodes(BT, to_delete);
    std::cout << "res: " << std::endl;
    for (auto it = res.begin(); it != res.end(); ++it)
        std::cout << (*it)->data << std::endl;
    return 0;
}