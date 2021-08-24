/* leetcode T19：删除链表的倒数第N个结点
 * 原题链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：快慢指针法
 *
 * 算法思想：
 * 利用快慢指针的思想，让快指针fast领先n+1个节点，当快指针走到链表尾nullptr时，慢指针slow位于倒数第n个节点的前一个节点
 * 然后进行删除即可。
 *
 * 易错点：
 * 1 while循环的终止条件
 * 2 最后的尾指针一定要置空
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，实际上只遍历了N-n个节点。
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

// 我的基于快慢指针的方法--快指针每次在慢指针更新后再向前移动
LinkList removeNthFromEnd(LinkList head, int n) {
    LNode *slow = head;// 慢指针
    LNode *fast;// 快指针
    int temp_n = n + 1;// 在while(n--)中，n会被重新赋值

    while (1) {// while (fast)
        fast = slow;
        n = temp_n;
        while (n--) {// fast指针快进n+个节点
            fast = fast->next;
            // 有无方法可以一次退出两个while循环？
            if (fast == nullptr) {// 这个代码太丑了
                fast = nullptr;
                break;
            }
        }
        if (fast == nullptr)// 这个代码太丑了
            break;
        slow = slow->next;
    }

    LNode *temp = slow->next;
    slow->next = temp->next;
    delete temp;// 释放内存

    return head;
}

// 方法二：快指针一开始就确定跟慢指针的距离
LinkList removeNthFromEnd2(LinkList head, int n) {
    LNode *slow = head, *fast = head;// 快慢指针
    n++;

    // 显式表明:fast = slow;
    // 快慢指针在起点出就确定二者距离--快慢指针的本质
    while (n--)// 快指针先快进几步--一开始就确定快慢指针的距离关系--重要
        fast = fast->next;

    while (fast) {// while (fast)
        slow = slow->next;
        fast = fast->next;
    }

    LNode *temp = slow->next;
    slow->next = temp->next;
    delete temp;// 释放内存

    return head;
}

/*测试*/
int main() {
    int num_list[10] = {1,2,3,4,5};
    LinkList list = nullptr;
    list = createList(num_list);
    // 原链表遍历结果
    printf("原链表遍历结果\n");
    traverseList(list);

    // 删除后的链表
    printf("删除后的链表\n");
    LinkList result = removeNthFromEnd2(list,5);
    traverseList(result);
}