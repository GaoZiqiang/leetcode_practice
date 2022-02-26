/* T2:两数相加 https://leetcode-cn.com/problems/add-two-numbers/
 * 思路：https://app.yinxiang.com/Home.action?_sourcePage=kpFf1eZWmGfiMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=PQ2S0ayPtXM3yWPvuidLz-TPR6I9Jhx8&login=true&username=gaoziqianghi%40163.com#n=8ed685f1-9aa8-4278-b7b1-3a442a34ed76&s=s3&ses=4&sh=2&sds=2&
 *
 * */

void merge(ListNode* head) {
    ListNode* work1 = head;
    while (work1 != nullptr) {
        if (work1->val >= 10) {
            // 末位进位-->添加新节点
            if (work1->next == nullptr) {
                ListNode* tmp = new ListNode();
                work1->next = tmp;
                tmp->next = nullptr;
            }
            work1->next->val += work1->val / 10;
            work1->val = work1->val %10;
        }
        work1 = work1->next;
    }
    return;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* work1 = l1;
    ListNode* work2 = l2;
    // 第一步：逐位相加
    while (work1 != nullptr) {
        if (work2 != nullptr) {
            work1->val += work2->val;
            work2 = work2->next;
        }
        if (work1->next == nullptr && work2 != nullptr) {
            work1->next = work2;// 直接将work2接到work1后边即可
            break;
        }
        work1 = work1->next;
    }

    // 第二步：进位
    merge(l1);
    return l1;
}