/* leetcode T121:买卖股票的最佳时机
 * 原题链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 * */

/* 方法一：一次遍历
 *
 * 算法思想：
 *
 * 关键点：
 * 使用minPrice记录之前的最小价格
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，一次遍历。
 * 空间复杂度：O(1)。
 * */


int maxProfit(vector<int>& prices) {
    int minPrice = prices[0], res = -1;

    for (int i = 1 ; i < prices.size(); i++) {
        if (prices[i] > minPrice) {
            res = max(res, prices[i] - minPrice);// 当前价格减去之前的最小价格
        }
        minPrice = min(minPrice, prices[i]);// 更新目前为止的最小价格
    }

    return res == -1 ? 0 : res;
}