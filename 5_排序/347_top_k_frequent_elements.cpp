/* leetcode T347:前 K 个高频元素
 * 原题链接：https://leetcode-cn.com/problems/top-k-frequent-elements/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：基于堆排序
 *
 * 算法思想：
 * 关键点一：使用哈希表，得到每个元素出现的频率
 * 关键点二：利用小根堆排序将出现频率排前k的元素留在堆中
 * 具体实现方法：建立小根堆
 * ①当堆中元素个数小于k时，新元素直接入堆；
 * ②当堆中元素个数大于等于k时，将新元素与堆顶元素进行比较，若堆顶元素小于新元素，则堆顶元素剔除，插入新元素；
 *
 * 改进一：
 * 使用emplace()代替push_back()存放临时对象到容器中，可以减少内存空间的使用
 *
 * 复杂度分析：
 * 时间复杂度：O(nlogk)，n为数组元素个数，logk为维护堆所需要的时间开销。
 * 空间复杂度：O(n)，unordered_map--n个元素和priority_queue--k个元素。
 * */

#include <unordered_map>
#include <algorithm>
#include <queue>

class Solution {
public:
    // 比较函数
    static bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
    // 实现方法
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> tmp_map;
        for (auto& num : nums) {
            tmp_map[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
        for (auto& [num, freq] : tmp_map) {
            if (pq.size() == k) {
                if (pq.top().second < freq) {
                    pq.pop();
                    pq.emplace(num, freq);
                }
            } else {
                pq.emplace(num, freq);
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            res.emplace_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};