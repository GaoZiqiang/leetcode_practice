/* leetcode T821:字符的最短距离
 * 原题链接：https://leetcode-cn.com/problems/shortest-distance-to-a-character/
 * */

/* 方法一：两次遍历
 * 算法思想：
 * 第一次从左到右遍历 计算每个元素到最左边的c的最短距离
 * 第二次从右到左遍历 计算每个元素到最右边的c的最短距离
 *
 * 关键点：
 * 1 lastc最近c的位置的初始化
 *  从左到右：lastc = -n
 *  从右到左：lastc = 2n
 *  这样能保证两次遍历每个元素到两边的距离一致
 * 2 lastc的更新
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O(1)。
 * */

#include <vector>

using namespace std;

vector<int> shortestToChar(string s, char c) {
    int n = s.size();
    vector<int> ans(n, 0);

    // 从左到右遍历
    int lastc = -n;// lastc初始化为-n
    for (int i = 0; i < n; i++) {
        // 记录(左边)距离元素i最近的c
        // lastc会更新
        if (s[i] == c) {
            lastc = i;
        }
        ans[i] = i - lastc;
    }

    // 从右到左遍历
    lastc = 2*n;// lastc初始化为2n
    for (int i = n - 1; i >= 0; i--) {
        // 记录(右边)距离元素i最近的c
        // lastc会更新
        if (s[i] == c) {
            lastc = i;
        }
        ans[i] = min(ans[i], lastc - i);
    }

    return ans;
}