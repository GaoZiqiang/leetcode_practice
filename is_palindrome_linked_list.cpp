/* leetcode T234:回文链表
 * 原题链接：https://leetcode-cn.com/problems/palindrome-linked-list/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：快慢指针
 *
 * 算法思想：
 * 我们可以将链表的后半部分反转（修改链表结构），然后将前半部分和后半部分进行比较。
 * 比较完成后我们应该将链表恢复原样。虽然不需要恢复也能通过测试用例，但是使用该函数的人
 * 通常不希望链表结构被更改。
 *
 * 整个流程可以分为以下五个步骤：
 *
 * 1 找到前半部分链表的尾节点。
 * 2 反转后半部分链表。
 * 3 判断是否回文。
 * 4 恢复链表。
 * 5 返回结果。
 *
 * 重要：
 * 使用快慢指针找中间节点：
 * 慢指针一次走一步，快指针一次走两步，快慢指针同时出发。当快指针移动到链表的末尾时，
 * 慢指针恰好到链表的中间。通过慢指针将链表分为两部分。
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，其中n指的是链表的大小。
 * 空间复杂度：O(1)，我们只会修改原本链表中节点的指向，而在堆栈上的堆栈帧不超过O(1)。
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

// 1 找中间节点
LNode * findMiddleNode(LinkList head) {
    LNode *slow = head->next, *fast = head->next;// 起点应该为第一个节点

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;// 返回中间节点
}

// 2 翻转后半部分链表
LNode * reverse(LinkList head) {
    LNode *work = head->next;
    LNode *temp;

    head->next = nullptr;// 链表尾指针置空

    while (work) {
        temp = work->next;

        // 头插法
        work->next = head->next;
        head->next = work;

        work = temp;
    }

    return head;// 返回翻转后链表的头结点
}

// 3 前后两部分进行回文比较
bool isPalindromeLinkedList(LinkList head) {
    LNode *middle_node = findMiddleNode(head);
    printf("middle_node->data: %d\n",middle_node->data);
    LNode *head_ = reverse(middle_node);
    printf("head_->data: %d\n",head_->data);

    LNode *work1 = head->next, *work2 = head_->next;

    while (work2) {
        if (work1->data != work2->data)
            break;
        work1 = work1->next;
        work2 = work2->next;
    }

    // 恢复原链表
    middle_node->next = reverse(head_)->next;
//    traverseList(head);

    if (work2)// 如果work2没有遍历完--work2提前遍历结束--中间有不匹配节点
        return false;

    return true;
}

int main() {
    int num_list[10] = {1,2,5,5,2,1};
    LinkList list = nullptr;
    list = createList(num_list);
    // 原链表遍历结果
    printf("原链表遍历结果\n");
    traverseList(list);

    if (isPalindromeLinkedList(list))
        printf("yes");
    else
        printf("no");
}