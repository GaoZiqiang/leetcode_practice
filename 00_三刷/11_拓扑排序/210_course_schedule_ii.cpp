/* leetcode T210:课程表II
 * 原题链接：https://leetcode-cn.com/problems/course-schedule-ii/
 * */

/* 方法一：拓扑排序
 *
 * 算法思想：
 * 1 依次统计各个节点的入度、统计入度为0的节点并入栈
 * 2 然后根据图的拓扑排序的思想对入度为0的栈中的节点依次出栈，并更新节点的入度以及栈内元素
 *
 * 关键点：
 * 本题的关键在于拓扑排序前的统计工作
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，一次遍历。
 * 空间复杂度：O(n)。
 * */

#include <vector>

using namespace std;
class Solution {
public:
    unordered_map<int, vector<int>> nodelist;// 每个节点的相邻(出度)节点
    unordered_map<int, int> inDegree;// 每个节点的入度
    stack<int> stack;// 存放入度为0的节点
    vector<int> res;

    // 统计各个节点的入度
    void countIndegree(vector<vector<int>>& prerequisites) {
        for (int i = 0; i < prerequisites.size(); i++) {
            inDegree[prerequisites[i][0]]++;
            nodelist[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
    }

    // 统计入度为0的节点并入栈
    void countZeroIndegNodes(int numCourses) {
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                stack.push(i);
            }
        }
    }

    // 拓扑排序
    vector<int> topSort(int numCourses) {
        while (!stack.empty()) {
            int top = stack.top();
            res.push_back(top);
            stack.pop();

            vector<int> list = nodelist[top];// 与top节点相邻(出度)的节点
            for (auto& x : list) {
                inDegree[x]--;// 与top节点相邻(出度)的节点入度减1
                if (inDegree[x] == 0) {// 将入度为0的节点入栈
                    stack.push(x);
                }
            }
        }

        if (res.size() != numCourses) {
            return {};
        }

        return res;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        countIndegree(prerequisites);
        countZeroIndegNodes(numCourses);
        return topSort(numCourses);
    }
};

// 我的解法
class Solution {
public:
    unordered_map<int, int> inDegree;// 各节点的入度
    unordered_map<int, vector<int>> adjNodes;// 每个节点的临接节点
    stack<int> stack;// 入度为0的节点
    vector<int> ans;// 存放结果

public:
    // 统计节点的入度和相邻节点
    void countInDegree(vector<vector<int>>& prerequisites) {
        for (int i = 0; i < prerequisites.size(); i++) {
            inDegree[prerequisites[i][0]]++;
            adjNodes[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return;
    }

    // 统计入度为0的节点
    void countZeroInDegree(int numCourses) {
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) stack.push(i);
        }
        return;
    }

    // 拓扑排序
    vector<int> topoSort(int numCourses) {
        while (!stack.empty()) {
            int top = stack.top();
            ans.push_back(top);
            stack.pop();

            auto nodes = adjNodes[top];
            for (auto& node : nodes) {
                inDegree[node]--;
                if (inDegree[node] == 0) stack.push(node);
            }
        }

        // 拓扑序列不存在时
        if (ans.size() != numCourses) return {};

        return ans;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        countInDegree(prerequisites);
        countZeroInDegree(numCourses);

        return topoSort(numCourses);
    }
};