/* leetcode T206:反转链表
 * 原题链接：https://leetcode-cn.com/problems/reverse-linked-list/
 * */

#include <malloc.h>
#include <stdio.h>

/* 方法一：基于遍历实现
 *
 * 算法思想一：
 * 借用原链表表头，每遍历一个节点，便将该节点头插到头结点之后，指头原表便利结束。
 *
 * 算法思想二：
 * 再创建一个链表--空间复杂度为O(n)
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，整个表遍历一遍。
 * 空间复杂度：O(1)，不需要额外的辅助空间。
 * */

typedef struct LNode {
    int data;
    struct LNode* next;
}LNode,*LinkList;

/*创建单链表*/
LinkList createList(int * num) {// LinkList是个指针--地址
    // 创建头结点
    LinkList head = (LinkList)malloc(sizeof(struct LNode));

    // 工作指针指向头结点
    LinkList p = head;// 创建工作指针p
    p->next = NULL;// 尾指针置空

    int i = 0;
    while(num[i])// 无法直接获取数组的长度
    {
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
void traverseList(LinkList head) {
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

// 方案一：在原链表的基础上进行翻转--共用一个表头
LinkList reverseList(LinkList L) {
    // 方案一：创建一个新链表
//    LinkList head = (LinkList)malloc(sizeof(struct LNode));// head是个指针--地址
//    head->next = nullptr;

    // 设置工作指针
    LNode *work, *temp;

    work = L->next;// L为原链表的头结点，头结点不存储信息的，值默认为0
    L->next = nullptr;// 头节点尾指针置空

    while (work) {
        // 暂存断点
        temp = work->next;
        // 头插法
        work->next = L->next;
        L->next = work;
        //返回断点
        work = temp;
    }

    return L;
}

// 方案一：创建一个新链表
LinkList reverseList2(LinkList L) {
    LinkList head = (LinkList)malloc(sizeof(struct LNode));// head是个指针--地址
    head->next = nullptr;
    // 设置工作指针
    LNode *work, *temp;

    work = L->next;// L为原链表的头结点，头结点不存储信息的，值默认为0

    while (work) {
        // 暂存断点
        temp = work->next;
        // 头插法
        work->next = head->next;
        head->next = work;
        //返回断点
        work = temp;
    }

    return head;
}

int main() {
    int num_list[10] = {1,2,3,4};
    LinkList list = nullptr;
    list = createList(num_list);
    // 原链表遍历结果
    printf("原链表遍历结果\n");
    traverseList(list);

    // 进行翻转
    // 方法一
    LinkList result = reverseList(list);
    // 方法二
//    LinkList result = reverseList2(list);

    // 翻转之后的链表遍历结果
    printf("翻转之后的链表遍历结果\n");
    traverseList(result);
}