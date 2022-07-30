/* leetcode T138:复制带随机指针的链表
 * 原题链接：https://leetcode.cn/problems/copy-list-with-random-pointer/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：回溯+递归
 *
 * 算法思想：
 * 参考：https://leetcode.cn/problems/copy-list-with-random-pointer/solution/fu-zhi-dai-sui-ji-zhi-zhen-de-lian-biao-rblsf/
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O(1)。
 * */


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // 记录每个节点对应的备份节点
    unordered_map<Node*, Node*> cachedNodes;
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        while (cachedNodes.count(head) == 0) {
            // 创建一个节点副本
            Node* newNode = new Node(head->val);
            // 将副本存入cachedNodes
            cachedNodes[head] = newNode;
            // 新节点的两个指针
            newNode->next = copyRandomList(head->next);// 递归查找
            newNode->random = copyRandomList(head->random);
        }

        return cachedNodes[head];
    }
};