/* leetcode T207: 课程表
 * 原题链接：https://leetcode.cn/problems/course-schedule/
 * */

/* 方法一：基于拓扑排序
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O(n)。
 * */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> inDegrees;
    stack<int> stack;

public:
    // 统计各节点入度
    void countInDegree(int numCourses, vector<vector<int>>& prerequisites) {
        // 所有节点的入度初始化为0--很重要！
        for (int i = 0; i < numCourses; i++) {
            inDegrees[i] = 0;
        }
        // 再根据prerequisites数组统计每个节点的入度
        for (int i = 0; i < prerequisites.size(); i++) {
            inDegrees[prerequisites[i][0]]++;
        }
        return;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 统计各节点入度
        countInDegree(numCourses, prerequisites);

        // 入度为0的节点入栈
        for (auto& [node, degree] : inDegrees) {
            if (degree == 0) {
                stack.push(node);
            }
        }

        int cnt = 0;
        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();
            cnt++;

            for (int i = 0; i < prerequisites.size(); i++) {
                if (prerequisites[i][1] == node) {
                    inDegrees[prerequisites[i][0]]--;
                    if (inDegrees[prerequisites[i][0]] == 0) {
                        stack.push(prerequisites[i][0]);
                    }
                }
            }

        }

        return cnt == numCourses;
    }
};