/* leetcode T102:二叉树的层序遍历
 * 原题链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 * */

#include <vector>
#include <iostream>
#include <queue>

/*两种宏?定义方式*/
#define ELE_TYPE char
//typedef char ELE_TYPE;
using namespace std;

/* 方法一：BFS广度优先遍历
 * 分析：
 * 借助队列，先进先出，按层进出，每一层的元素，每出一个元素，其左右孩子接单全部入队
 *
 * 复杂度分析：
 * 时间复杂度：O(n) 树中每个元素进队、出队各一次
 * 空间复杂度：O(n) 需要一个长度为n的辅助队列
 * */

/*存储结构*/
typedef struct TreeNode {
    ELE_TYPE data;
    struct TreeNode *lchild, *rchild;
}BiTNode;

/*声明树的根节点（的地址）*/
typedef TreeNode *BiTree;// 创建首指针 一个地址/指针而已

/*按照先序遍历的顺序创建树*/
void createBiTreePre(BiTree &BT) {// 使用引用，不会改变原数组的地址，在原数组的基础上进行修改
    ELE_TYPE ch;
    cout << "请输入节点数值:" << endl;
    cin >> ch;// 这里输入的字符会转换成ASSIC码

    /*创建左右子树*/
    if (ch == '0')// 叶子节点后为'0'
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


/*层次遍历实现方式*/
vector<vector<ELE_TYPE>> level_traverse(BiTree &root) {
    vector<vector<ELE_TYPE>> res;// 存放遍历的结果

    /*创建队列*/
    queue <BiTNode *> q;

    /*二叉树根节点入队*/
    q.push(root);// root既是数组的首指针，也是第一个元素 root[0]

    int j = 0;
    while(!q.empty()) {
        j += 1;
        cout << "第 " << j << " 层元素：" << endl;

        int n = q.size();// 栈当前元素个数-即当前层的元素个数
        vector<ELE_TYPE> level;// 存放每一层的所有节点

        /*将当前层的所有元素全部出栈，（建立层的概念）*/
        for (int i = 0; i < n; i ++) {

            auto node = q.front();// 或者队尾元素
            level.push_back(node->data);// 保存
            cout << "元素 " << i + 1 << ":" << node->data << endl;
            q.pop();// 出队

            /*判断左右子树*/
            if (node->lchild)
                q.push(node->lchild);
            if (node->rchild)
                q.push(node->rchild);
        }

        /*将每一层的遍历节点存入总结果*/
        res.push_back(level);
    }

}

/*测试*/
int main() {
    BiTree BT;
    /*创建二叉树*/
    cout << "------ 创建二叉树 ------" << endl;
    createBiTreePre(BT);

    cout << "------ 层次遍历 ------" << endl;
    level_traverse(BT);


}
