/* leetcode T451:根据字符出现频率排序
 * 原题链接：https://leetcode-cn.com/problems/sort-characters-by-frequency/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：基于桶排序
 *
 * 算法思想：
 * 关键点一：统计各个字符出现的次数
 * 关键点二：按各字符的出现频率进行排序
 * 关键点三：拼接结果字符串
 *
 * 复杂度分析：
 * 时间复杂度：O(n + klogk)，n为字符串中字符总数，k为字符串中字符的种类数。
 * O(n)为遍历字符串的时间开销，O(klogk)为对occurences数组进行排序所需时间开销。
 * 空间复杂度：O(n + k)，哈希表和存放结果的vector。
 * */

#include <unordered_map>
#include <queue>
class Solution {
public:
    static bool cmp(const pair<char, int>& p1, const pair<char, int>& p2) {
        return p1.second > p2.second;
    }

    string frequencySort(string s) {
        // 统计各个字符出现的次数
        unordered_map<char, int> occurences;
        for (auto& x : s) {
            occurences[x]++;
        }

        // 调整数据格式
        vector<pair<char, int>> sorted_occus;
        for (auto x : occurences) {
            sorted_occus.emplace_back(x.first, x.second);
        }

        // 按各字符的出现频率进行排序
        sort(sorted_occus.begin(), sorted_occus.end(), cmp);

        // 拼接结果字符串
        string res = "";
        for (auto& [ch, freq] : sorted_occus) {
            for (int i = 0; i < freq; i++) {
                res += ch;
            }
        }

        return res;
    }
};