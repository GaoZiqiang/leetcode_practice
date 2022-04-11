/* leetcode T684:冗余连接
 * 原题链接：https://leetcode-cn.com/problems/redundant-connection/
 * */

/* 方法二：并查集
 * 算法思想：参考https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
 * 重点在于问题的转换
 *
 * 复杂度分析：
 * 时间复杂度：O(nlogn)。
 * 空间复杂度：O(n)，parent数组。
 * */


#include <vector>

using namespace std;

int Find(vector<int>& parent, int index) {
    if (parent[index] != index) {
        parent[index] = Find(parent, parent[index]);
    }
    return parent[index];
}

void Union(vector<int>& parent, int index1, int index2) {
    parent[Find(parent, index1)] = Find(parent, index2);
    return;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parent(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (auto& edge : edges) {
        int node1 = edge[0], node2 = edge[1];
        if (Find(parent, node1) != Find(parent, node2)) {
            Union(parent, node1, node2);
        } else {
            return edge;
        }
    }

    return {};
}