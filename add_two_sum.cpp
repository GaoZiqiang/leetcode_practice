//#include "stdafx.h"
#include <malloc.h>
#include <stdio.h>

typedef struct NODE
{
    int data;
    struct NODE* pNext;

}NODE,*PNODE;

PNODE Create_list(int * num);
void Traversal_list(PNODE pHead);

//void addTwoSum();
PNODE addTwoSum(PNODE l1, PNODE l2);

int main()
{

    int num1[10] = {2, 4, 3};
    PNODE pHead1 = NULL;
    pHead1 = Create_list(num1);
    Traversal_list(pHead1);

    int num2[10] = {5, 6, 4};
    PNODE pHead2 = NULL;
    pHead2 = Create_list(num2);
    Traversal_list(pHead2);

    PNODE result = addTwoSum(pHead1, pHead2);

    Traversal_list(result);
//    getchar();
    return 0;
}
PNODE Create_list(int * num)
{
    int i;
    //int num[10] = {1,2,3,4,5,6,7,8,9,10};
    PNODE pHead = (PNODE)malloc(sizeof(struct NODE));
    PNODE p = pHead;
    p->pNext = NULL;
    for (i=0;i<10;i++)
    {
        PNODE pNew = (PNODE)malloc(sizeof(struct NODE));

        pNew->data = num[i];
        p->pNext = pNew;
        pNew->pNext = NULL;
        p=pNew;
    }
    return pHead;
}
void Traversal_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while(p)
    {
        printf("%d  ",p->data);
        p = p->pNext;
    }
    printf("\n");
    return;
}

PNODE addTwoSum(PNODE l1, PNODE l2) {
    PNODE head = nullptr, tail = nullptr;// 头指针、尾指针
    int temp = 0;// 进位
    while(l1 != nullptr || l2 != nullptr) {
        int values = l1->data + l2->data + temp;
        temp = values / 10;
        if (values < 10)
            values = values;
        else
            values = values % 10;

        if (head == nullptr) {
            head = tail = (PNODE)malloc(sizeof(struct NODE));
        }else {
            PNODE pNew = (PNODE)malloc(sizeof(struct NODE));
            pNew->data = values;

            tail->pNext = pNew;
            tail = pNew;
        }
        if (l1)
            l1 = l1->pNext;
        if (l2)
            l2 = l2->pNext;
    }

    if (temp > 0) {
        PNODE pNew = (PNODE)malloc(sizeof(struct NODE));
        tail->pNext = pNew;
        tail = pNew;
    }

    return head;
}