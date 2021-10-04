/* leetcode T406:根据身高重建队列
 * 原题链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height/
 * */

#include <vector>
#include <algorithm>
#include <stdio.h>

/* 方法一：先排序再插入--高个子站好，矮个子插入
 * 1.排序规则：按照先H高度降序，K个数升序排序
 * 2.遍历排序后的数组，根据K插入到K的位置上
 *
 * 核心思想：高个子先站好位，矮个子插入到K位置上，前面肯定有K个高个子，矮个子再插到前面也满足K的要求
 *
 * 复杂度分析：
 * 时间复杂度：O(nlogn)，排序用时。
 * 空间复杂度：O(logn)，排序所用栈空间。
 * */

using namespace std;

// 排序--先身高，再k
int cmpByHeightK(const vector<int> & x, const vector<int> & y) {
    return x[0] == y[0] ? x[1] < y[1] : x[0] > y[0];// 高的在前 k小的在前
}

vector<vector<int>> reconstQueueByHeight(vector<vector<int>> & heights) {
    // 按照身高和k排序
    sort(heights.begin(), heights.end(), cmpByHeightK);
    // 插队/插入排序
    vector<vector<int>> ans;
    for (vector<int> heigth : heights)
        ans.insert(ans.begin() + heigth[1], heigth);// 队列第heights[i][1]的位置上插入heights[i]

    return ans;
}

// 测试
int main() {
    vector<vector<int>> heights = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> res = reconstQueueByHeight(heights);
    for (int i = 0; i < res.size(); i++)
        printf("[%d,%d] ", res[i][0],res[i][1]);
}