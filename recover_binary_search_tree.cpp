#include <vector>
#include <iostream>
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

/*节点访问函数*/
void visit(BiTNode *node) {
    cout << "visited node:" << node->data << endl;
}

// 递归中序遍历
void inorder(BiTree &root,vector<int> &nums) {
    if (root == nullptr)
        return;
    inorder(root->lchild,nums);
    nums.push_back(root->data);
    visit(root);
    inorder(root->rchild,nums);
}

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
    int count = 0;// 记录出错的元素次数
    for (int i = 0; i < n; i++) {
        if(nums[i+1] < nums[i]) {
            count += 1;
            if (count == 1)// 第一次
                x = nums[i];// x存大的，第一次大的为错序的 大的被换到前面去了
            else if (count == 2)// 第二次
                y = nums[i+1];// y存小的，第二次小的为错序的 小的被换到后面去了
        }
    }

    return {x, y};
}

// 先序遍历递归recover
void recover(BiTree &r, int count, int x, int y) {
    if (r != nullptr) {
        if (r->data == x)// 第一个出错的元素，大的，x
            r->data = y;// 重新赋值为小的，y
        else if (r->data == y)// 第二个出错的元素，小的，y
            r->data = x;// 重新赋值为大的，x
        count -= 1;// 修正一个
        if (count == 0)
            return;
    }
    recover(r->lchild, count, x, y);
    recover(r->rchild, count, x, y);
}

// recover
void recoverTree(BiTree &root) {
    vector<int> nums;
    inorder(root,nums);
    pair<int,int> swapped = findTwoSwapped(nums);
    recover(root, 2, swapped.first, swapped.second);
}

int main() {
    BiTree BT;

    /*创建树*/
    createBiTreePre(BT);
    cout << "修正之前的遍历结果" << endl;
    recoverTree(BT);

    cout << "修正之后的遍历结果" << endl;
    inorder_traverse(BT);
}