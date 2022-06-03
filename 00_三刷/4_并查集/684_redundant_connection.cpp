/* leetcode T684:冗余连接
 * 原题链接：https://leetcode-cn.com/problems/redundant-connection/
 * */

/* 方法二：并查集
 * 算法思想：参考https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
 * 重点在于问题的转换
 * -->如果边的两个节点已经出现在同一个集合里，说明着边的两个节点已经连在一起了，如果再加入这条边一定
 * 就出现环了。
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
    parent[Find(parent, index1)] = Find(parent, index2);// 让index1的祖先认index2的祖先为祖先
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
            return edge;// 该边的两个端点有公共祖先-->加入该边会形成环路-->故舍弃
        }
    }

    return {};
}