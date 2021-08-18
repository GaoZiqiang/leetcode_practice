/* leetcode T328：奇偶链表
 * 原题链接：https://leetcode-cn.com/problems/odd-even-linked-list/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：奇偶节点分离再合并
 *
 * 算法思想：
 * 借鉴赵中间节点的思想，通过指针每次移动两个节点，使两起点错位，从而实现奇、偶节点分类的目的。
 *
 * 易错点：
 * 1 while循环的终止条件
 * 2 最后的尾指针一定要置空
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，其中n指的是链表的大小。
 * 空间复杂度：O(1)，只需维护有限的指针。
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

LinkList oddEvenList(LinkList head) {// LinkList oddEvenList(LinkList head)
    // 冗余指针过多，有待优化
    LNode *odd = head->next, *even = head->next->next;
    LNode *work_odd, *work_even;

    work_odd = odd;
    work_even = even;

    LNode *head_odd = odd, *head_even = even;// 暂存奇链表的头结点--伪头结点

    while (odd && even) {// 循环终止条件还有待优化
        if (odd->next->next) {
            odd = odd->next->next;
            work_odd->next = odd;
            work_odd = odd;
        } else {
            even->next = nullptr;// 尾指针一定要置空，不然链表会无限遍历，没有终止
            break;
        }

        if (even->next->next) {
            even = even->next->next;
            work_even->next = even;
            work_even = even;
        } else {
            even->next = nullptr;
            break;
        }
    }

    work_odd->next = head_even;
    head->next = head_odd;
}

/*测试*/
int main() {
    int num_list[10] = {1,2,3,4,5,6,7};
    LinkList list = nullptr;
    list = createList(num_list);
    // 原链表遍历结果
    printf("原链表遍历结果\n");
    traverseList(list);

    LinkList result = oddEvenList(list);
    traverseList(result);
}