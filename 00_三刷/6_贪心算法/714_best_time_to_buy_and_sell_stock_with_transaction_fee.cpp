/* leetcode T714:买卖股票的最佳时机含手续费
 * 原题链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 * */

/* 方法一：贪心算法+一阶差分
 *
 * 算法思想：
 * 算法思想同T122:买卖股票的最佳时机 II
 * 不同点：
 * 本题存在交易手续费fee，在“虚拟卖出”操作中会产生多次fee
 * -->因此为了抵消多产生的fee，需要做一个处理：
 * -->每次更新pre时，将pre定义为pre = prices[i]-fee
 * -->这样在计算ans += prices[i] - pre - fee时实际为ans += prices[i] - pre(+fee) - fee
 * 从而抵消之前“多减”的fee
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，一次遍历。
 * 空间复杂度：O(1)，不需要额外空间。
 *
 * 方法二：动态规划
 *
 * 算法思想：参考https://www.programmercarl.com/0122.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAII%EF%BC%88%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%EF%BC%89.html#%E6%80%9D%E8%B7%AF
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，一次遍历。
 * 空间复杂度：O(n*2)，dp数组。
 * */


#include <vector>

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    int pre = prices[0];
    int ans = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] < pre) pre = prices[i];
        if (prices[i] > pre + fee) {
            ans += prices[i] - pre - fee;
            pre = prices[i] - fee;// 抵消"虚拟卖出"产生的fee
        }
    }

    return ans;
}