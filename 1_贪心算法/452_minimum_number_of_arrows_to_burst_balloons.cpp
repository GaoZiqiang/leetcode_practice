/* leetcode T452:用最少数量的箭引爆气球
 * 原题链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
 * */

#include <vector>
#include <stdio.h>
#include <algorithm>

/* 方法一：排序+贪心
 *
 * 算法思想：
 * 核心思想：
 * 类似于T435--https://leetcode-cn.com/problems/non-overlapping-intervals/
 * 1 对各区间按照右端点升序排序；
 * 2 取points[0][1]为第一只箭prev，
 * ① 若points[i][0]<=prev，说明这两个区间有公共区间-->可以共用一支箭--注意：此时continue，prev认为第一个区间的右端点
 * ② 若points[i][0]>prev，则说明该两个区间已经不能共用同一支箭-->nums++，同时更新prev--prev=points[i][1]
 *
 * 复杂度分析：
 * 时间复杂度：O(nlogn)，排序开销为O(nlogn)，遍历开销为O(n)；
 * 空间复杂度：O(logn)，排序需使用的栈开销；
 * */

using namespace std;

/*按照区间尾部元素升序排序*/
int cmpByTail(const vector<int> &x, const vector<int> &y) {
    return x[1] < y[1];
}

/*官方解法*/
int findMinArrowShots(vector<vector<int>> &points) {
    if (points.empty())
        return 0;

    // 按照区间尾部元素升序排序
    // 排序方法1
    //sort(pointers.begin(), pointers.end(), cmpByTail);
    // 排序方法2
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    });

    // 注意：arrow_num从1开始--初始一支箭
    int arrow_num = 1, len = points.size();
    int prev = points[0][1];// 暂存--比较右端点

    for (int i = 1; i < len; i++) {// 从i=1开始，第一个作为保留
        if (points[i][0] <= prev)// 有公共区间--不用换箭
            continue;// 判断下一个
        else {// 没有公共区间
            prev = points[i][1];// 更新prev
            arrow_num++;// 再换一支箭
        }
    }
    return arrow_num;
}

// 我的解法
int findMinArrowShots(vector<vector<int>>& points) {
    int n = points.size();
    int res = n;

    // 按照x_start/左边界排序
    std::sort(points.begin(), points.end());

    int prev = points[0][1];
    for (int i = 1; i < n; i++) {
        if (points[i][0] <= prev) {// 存在重叠区域
            prev = min(prev, points[i][1]);// 更新prev
            res--;// 箭数减1
        } else {// 没有重叠区域
            prev = points[i][1];
        }
    }

    return res;
}