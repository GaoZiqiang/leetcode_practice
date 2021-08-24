/* leetcode T24:两两交换链表中的节点
 * 原题链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 * */

#include <malloc.h>
#include <stdio.h>

/* 方法一：迭代
 *
 * 问题难点：
 * 头结点的处理和遍历结束（最后两个节点）的处理
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，节点的总个数。
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
void traverseList(LinkList head) {
    // 从head之后的第一个节点开始遍历
    LinkList p = head->next;// 头指针不保存data
    while(p)
    {
        printf("%d  ",p->data);
        p = p->next;
    }
    printf("\n");

    return;
}

/*成对交换两节点*/
LinkList swapNodePair(LinkList L) {
    LNode * work, * pre, * temp, * ppre;
//    printf("1\n");
    ppre = L;
    pre = L->next;
    work = pre->next;//work = L->next->next;

    temp = nullptr;

//    L->next = work;

    while(work) {// 使用work指针做判断即可，不需要pre和work两个指针
        temp = pre;// 暂存断点位置

        // 进行交换
        pre->next = work->next;
        work->next = pre;
        ppre->next = work;// 防止断链

        if(pre->next)
            pre = pre->next;
        else
            break;
        if(pre->next)
            work = pre->next;

        ppre = temp;// 更新断点位置
    }

    if (pre)
        pre->next = nullptr;

    if (!pre && !work)
        work->next = nullptr;

    return L;
}

/*测试*/
int main() {
    int num[9] = {1,2,3,4,5,6};
    LinkList list = nullptr;
    list = createList(num);
    // 原链表
    printf("原链表\n");
    traverseList(list);

    LinkList result = swapNodePair(list);
    // 交换后的链表
    printf("交换后的链表\n");
    traverseList(result);
}