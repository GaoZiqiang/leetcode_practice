/* leetcode T1094:拼车
 * 原题链接：https://leetcode-cn.com/problems/car-pooling/
 * */

/* 方法一：差分法
 *
 * 算法思想：参考https://app.yinxiang.com/Home.action?login=true#n=578f61fd-de47-44a9-b678-ce4ce27ef632&s=s3&ses=4&sh=2&sds=2&
 *
 * 关键点：
 * 1 这里不需要arr数组，或者说arr数组为{0}数组
 * 2 差分数组d初始化为{0}
 * 3 本题在对标记后的差分数组d求前缀和时需要对d[i] > capacity进行判断，因此建议for循环从i=0开始
 *
 * 复杂度分析：
 * 时间复杂度：O(2*trips.size() + n)，
 * 空间复杂度：O(1)，有限长数组d。
 * */

#include <vector>

using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    // 定义差分数组
    vector<int> d(1002, 0);

    // 标记差分数组
    for (auto& trip : trips) {
        if (trip[0] > capacity) return false;
        d[trip[1]] += trip[0];
        d[trip[2]] -= trip[0];
    }

    // 差分数组求前缀和
    for (int i = 0; i <= 1000; i++) {// i从1开始会漏掉对d[0] > capacity的判断
        if (i > 0) d[i] += d[i-1];
        if (d[i] > capacity)
            return false;
    }

    return true;
}