/* leetcode T93:复原 IP 地址
 * 原题链接：https://leetcode-cn.com/problems/restore-ip-addresses/
 * */

/* 方法一：回溯法
 *
 * 算法思想：
 * 回溯：
 * 有规则的遍历所有可能的组合
 *
 * 复杂度分析：
 * 时间复杂度：O(3^4 * |s|)。
 * 空间复杂度：O(4)。
 * */


#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    const int SEG_NUM = 4;

private:
    vector<string> res;
    vector<int> segments;

public:
    void dfs(const string& s, int segId, int segStart) {
        // 回溯终止条件
        // 终止条件1 找到了4段ip地址 并遍历完了整个字符串
        if (segId == SEG_NUM) {
            if (segStart == s.size()) {
                string tmpIp;
                for (int i = 0; i < SEG_NUM; i++) {
                    tmpIp += to_string(segments[i]);
                    if (i != SEG_NUM - 1) {
                        tmpIp += ".";
                    }
                }
                res.push_back(tmpIp);
            }
            return;
        }

        // 终止条件2 还未找到4段ip地址就已经遍历完了整个字符串-->提前回溯 直接返回，结果不存入res
        if (segStart >= s.size()) {
            return;
        }


        // 横向遍历
        // 情形1 当前数字为0 该段ip为0
        if (s[segStart] == '0') {
            segments[segId] = 0;
            dfs(s, segId + 1, segStart + 1);
        }

        // 情形2 一般情况 从小到大拓展每个segment的长度
        int segIp = 0;
        for (int segEnd = segStart; segEnd < s.size(); segEnd++) {
            segIp = segIp * 10 + (s[segEnd] - '0');
            if (segIp > 0 && segIp <= 0xFF) {// 判断当前segment是否有效
                segments[segId] = segIp;
                dfs(s, segId + 1, segEnd + 1);
            } else {
                break;
            }
        }

        return;
    }

    vector<string> restoreIpAddresses(string s) {
        segments.resize(SEG_NUM);
        dfs(s, 0, 0);
        return res;
    }
};