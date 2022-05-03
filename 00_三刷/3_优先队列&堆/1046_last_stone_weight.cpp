/* leetcode T1046:最后一块石头的重量
 * 原题链接：https://leetcode-cn.com/problems/last-stone-weight/
 * */

/* 方法一：优先队列/堆/大顶堆
 *
 * 算法思想：
 * 将stones数组转换为大顶堆
 *
 * 复杂度分析：
 * 时间复杂度：O(nlogn)，每次从队列中取出元素并重新排序需要花费O(logn)的时间，最多共需要粉碎n−1次石头。
 * 空间复杂度：O(n)。
 * */

#include <queue>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int, vector<int>, less<int>> q(stones.begin(), stones.end());// 大顶堆

    while (q.size() > 1) {
        int maxStone = q.top();
        q.pop();
        int secStone = q.top();
        q.pop();
        // 两个石头不相等 存入差值
        if (maxStone != secStone) q.push(abs(maxStone - secStone));
    }

    return q.empty() ? 0 : q.top();
}