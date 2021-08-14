/* leetcode T160:相交链表
 * 原题链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 * */

#include <malloc.h>
#include <stdio.h>

/* 方法一：双指针法
 *
 * 参见方法二：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode-solutio-a8jn/
 *
 * 大体思路：
 * x->x->x->x(a)
 *          |
 *          x->x->x(c)
 *          ^
 *          |
 *       x->x(b)
 * 在a指针移动a+c距离和b指针移动b+c+(a-b)距离之后，两指针来到同一个起跑线，然后移动同时移动b个距离即a指针共移动
 * a+c+b个节点距离，b指针共移动b+c+a节点距离之后，二者相遇，到达相交节点。
 *
 * 复杂度分析：
 * 时间复杂度：O(m+n)，两个指针同时遍历两个链表，每个指针各遍历每个链表一次O(m+n+a+b)
 * 空间复杂度：O(1)，不需要额外的辅助空间。
 * */

typedef struct LNode {
    int data;
    struct LNode* next;
}LNode,*LinkList;

/*创建单链表*/
LNode * createList(int * num) {// LinkList是个指针--地址
    // 创建头结点
    LNode * head = (LNode *)malloc(sizeof(struct LNode));// 头结点是空的？
//    head->data = num[0];
    // 工作指针指向头结点
    LinkList p = head;// 创建工作指针p
    p->next = NULL;// 尾指针置空

    int i = 0;
    while(num[i])// 无法直接获取数组的长度--这样有一个bug:num[i]为0时，退出
    {
//        printf("i: %d\n",i);
//        printf("num: %0x\n",num);
        LinkList new_node = (LinkList)malloc(sizeof(struct LNode));

        new_node->data = num[i];
        // 尾插法
        p->next = new_node;
        new_node->next = NULL;
        p = new_node;
        i++;
    }

    return head;
}

/*单链表遍历*/
void traverseList(LNode * head) {
    // 从head之后的第一个节点开始遍历
    LinkList p = head->next;
    while(p)
    {
        printf("%d  ",p->data);
        p = p->next;
    }
    printf("\n");

    return;
}


// 最大的问题：如何定义两个节点相同？？？work1 == work2就是两个节点相同？？？
// 答：两个节点相同是指两个节点的内存位置和内存空间一致
LNode * getIntersectionNode(LNode * La, LNode * Lb) {
    if (La == nullptr || Lb == nullptr)
        return nullptr;

    LNode * work1 = La, * work2 = Lb;

    while(work1 != work2) {
        work1 = work1 ? work1->next : Lb;
        work2 = work2 ? work2->next : La;
    }
    return work1;
}

/*测试*/
// 因为无法创建具有公共节点的链表，所以暂时无法测试--使用leetcode官网测试
int main() {
//    int num1[9] = {1,2,4,5,6};
//    LNode * list1 = nullptr;
//    list1 = createList(num1);
//
//    int num2[9] = {8,7,9,4,5,6};
//    LNode * list2 = nullptr;
//    list2 = createList(num2);
//
//    // 原链表
//    printf("原链表\n");
//    traverseList(list1);
//    traverseList(list2);
//
//    LNode * result = getIntersectionNode(list1, list2);
//    printf("intersection node: %d\n",result->data);
}

// 用于leetcode提交测试
class Solution {
public:
    ListNode * getIntersectionNode(ListNode * La, ListNode * Lb) {
        if (La == nullptr || Lb == nullptr)
            return nullptr;

        ListNode * work1 = La, * work2 = Lb;

        while(work1 != work2) {
            work1 = work1 ? work1->next : Lb;
            work2 = work2 ? work2->next : La;
        }
        return work1;
    }
};