/* leetcode T122:买卖股票的最佳时机 II
 * 原题链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 * */

#include <vector>
#include <stdio.h>

/* 方法一：贪心算法
 * 贪心算法--从小处着手--有利可图就上--
 * 在每两个相邻的日子里，只要有利可图（股票升值），都赚取其中的差价即可。
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，一次遍历。
 * 空间复杂度：O(1)，不需要额外空间。
 * */

using namespace std;

int maxProfit(vector<int> & prices) {
    int len = prices.size();
    int tmp, profit;
    tmp = prices[0];

    for (int i = 1; i < len; i++) {
        if (prices[i] > tmp)// 相邻两天有差价--有利可图--卖出
            profit += (prices[i] - tmp);
        tmp = prices[i];
    }

    return profit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int profit = maxProfit(prices);
    printf("profit: %d\n",profit);
}