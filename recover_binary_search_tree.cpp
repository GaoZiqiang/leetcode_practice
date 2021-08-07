/* leetcode T99:恢复二叉搜索树
 * 原题链接：https://leetcode-cn.com/problems/recover-binary-search-tree/
 * */

#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>

/*两种宏?定义方式*/
#define ELEM_TYPE int
//typedef char ELEM_TYPE;
using namespace std;

/* 方法一：显式中序遍历法
 *
 * 整体算法思想如下：
 * 1 找到二叉搜索树中序遍历得到值序列的不满足条件的位置
 * 2 将位置出现问题的元素找出
 * 3 将出问题的两个元素恢复原位置
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，两次遍历（中序遍历和recover）需要O(n)，查找x和y需要O()，共计O(n)
 * 空间复杂度：O(n)，需要一个长度为n的数组存放遍历结果
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
    if (ch == 0)// 叶子节点后为'0'--输入'0'表示节点结束，没有子节点 切记：此处ch值类型为char
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

/*节点访问函数*/
void visit(BiTNode *node) {
    cout << "visited node:" << node->data << endl;
}

// 递归中序遍历并返回遍历结果
void inorder(BiTree &root,vector<int> &nums) {
    if (root == nullptr)
        return;
    inorder(root->lchild,nums);
    nums.push_back(root->data);
    visit(root);
    inorder(root->rchild,nums);
}

// 只进行中序遍历，并打印输出遍历结果
void inorder_traverse(BiTree &root) {
    if (root == nullptr)
        return;
    inorder_traverse(root->lchild);
    visit(root);
    inorder_traverse(root->rchild);
}

// 找到错序的元素
pair<int,int> findTwoSwapped(vector<int> nums) {
    int n = nums.size();
    int x = -1, y = -1;// x y的初始值定义为-1 x存大的，y存小的
//    int count = 0;// 记录出错的元素次数
    for (int i = 0; i < n - 1; ++i) {// 为什么？？？
        if(nums[i+1] < nums[i]) {
            y = nums[i+1];
            if (x == -1)
                x = nums[i];
        }
    }

    return {x, y};
}

// 先序遍历递归recover
void recover(BiTree &root, int count, int x, int y) {
    if (root != nullptr) {
        if (root->data == x || root->data == y) {
            root->data = root->data == x ? y : x;
            if (--count == 0) {
                return;
            }
        }
        recover(root->lchild, count, x, y);
        recover(root->rchild, count, x, y);
    }


}

// recover
void recoverTree(BiTree &root) {
    vector<int> nums;
    /*得到中序遍历的结果*/
    inorder(root,nums);

    /*找到被交换的--有问题的 节点*/
    pair<int,int> swapped = findTwoSwapped(nums);

    /*进行恢复*/
    recover(root, 2, swapped.first, swapped.second);
}

/*测试*/
int main() {
    BiTree BT;

    /*创建树*/
    createBiTreePre(BT);
    cout << "修正之前的遍历结果" << endl;
    recoverTree(BT);

    cout << "修正之后的遍历结果" << endl;
    inorder_traverse(BT);
}