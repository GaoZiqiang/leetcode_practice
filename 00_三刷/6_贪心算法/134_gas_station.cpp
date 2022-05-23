/* T134:加油站 https://leetcode.cn/problems/gas-station/
 *
 * 方法一：暴力解法
 *
 * 算法思想：
 * 使用rest记录上次剩下的gas
 * if (rest + gas[i%n] < cost[i%n])-->失败
 *
 * 计算rest:
 * rest = rest + gas[i%n] - cost[i%n];
 *
 *
 * 关键点：
 * 使用i%2n解决循环问题
 *
 * 时间复杂度：O(n)，2n。
 * 空间复杂度：O(1)。
 * */

#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int rest = 0;// 上一次的剩余gas
    int count = 0, ans = -1;

    for (int i = 0; i < 2*n; i++) {
        if (rest + gas[i%n] < cost[i%n]) {
            count = 0;
            rest = 0;
            continue;
        }

        count++;
        if (count == n) return (i+1)%n;

        rest = rest + gas[i%n] - cost[i%n];
    }

    return -1;
}