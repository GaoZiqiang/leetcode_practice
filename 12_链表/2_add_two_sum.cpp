/* leetcode T2:两数相加
 * 原题链接：https://leetcode-cn.com/problems/add-two-numbers/
 * */

#include <malloc.h>
#include <stdio.h>

/* 方法一：基于遍历实现两链表元素相加
 * 关键点1：
 * 进位
 * 关键点2：
 * 两链表长度不一，一个链表遍历完成
 *
 * 复杂度分析：
 * 时间复杂度：O(max(m,n))，其中 mm 和 nn 分别为两个链表的长度。
 * 空间复杂度：O(1)
 * */

typedef struct LNode {
    int data;
    struct LNode* next;
}LNode,*LinkList;

/*创建单链表*/
LinkList createList(int * num) {
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
    LinkList p = head->next;
    while(p)
    {
        printf("%d  ",p->data);
        p = p->next;
    }
    printf("\n");

    return;
}

/*两链表元素相加*/
LinkList addTwoSum(LinkList l1, LinkList l2) {
    LinkList head = nullptr, tail = nullptr;// 头指针、尾指针
    int temp = 0;// 进位

    while(l1 != nullptr || l2 != nullptr) {
        int data1 = l1 ? l1->data : 0;
        int data2 = l2 ? l2->data : 0;
        int values = data1 + data2 + temp;
        temp = values / 10;

        if (values < 10)
            values = values;
        else
            values = values % 10;

        if (head == nullptr) {
            head = tail = (LinkList)malloc(sizeof(struct LNode));
        }else {
            LinkList new_node = (LinkList)malloc(sizeof(struct LNode));
            new_node->data = values;
            // 尾插法
            tail->next = new_node;
            tail = new_node;
        }
        if (l1)
            l1 = l1->next;

        if (l2)
            l2 = l2->next;
    }

    if (temp > 0) {
        LinkList new_node = (LinkList)malloc(sizeof(struct LNode));
        tail->next = new_node;
        tail = new_node;
    }

    tail->next = nullptr;// 尾指针置空

    return head;
}

/*测试*/
int main()
{
    // 创建单链表1
    int num1[10] = {5,4,3,1};
    LinkList list1 = NULL;
    list1 = createList(num1);
    traverseList(list1);

    // 创建单链表2
    int num2[10] = {5,6,4};
    LinkList list2 = NULL;
    list2 = createList(num2);
    traverseList(list2);

    // 两链表相加
    LinkList result = addTwoSum(list1, list2);
    // 遍历输出
    traverseList(result);

    return 0;
}