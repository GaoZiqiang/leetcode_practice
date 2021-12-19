/* leetcode T413:等差数列划分
 * 原题链接：https://leetcode-cn.com/problems/arithmetic-slices/
 * */

/* 方法一：动态规划
 *
 * 算法思想：
 * 核心：
 * 每三个元素一组进行判断，只要连续三个元素就满足一个等差数列
 * 判断条件：nums[i] - nums[i-1] == nums[i-1] - nums[i-2]
 *
 *
 * 关键点：
 * 以[1,2,3,4]为例：
 * 1 2 3、2 3 4都符合数列规则，问题在于如何统计1 2 3 4
 * 解决方法：
 * 以每个位置i的作为终点时，在这之前所有满足条件的子数组个数，用数组dp[i]记录
 * 对于位置i+1，若以i+1为终点的三个元素满足等差数列，则意味着若元素i+1之前的元素如果满足等比数列，则加上元素i+1
 * 后仍然满足等比数列，因此通过dp[i+1] = dp[i]+1统计以i+1元素为终点的满足等比数列的子数组个数。反之，若果dp[i]等于0，
 * 则仍然不影响dp[i+1]的计算
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，遍历数组。
 * 空间复杂度：O(n)，数组。
 * * */

// 实现方法
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int numberOfArithmetricSlices(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    for (int i = 2; i < n; i++) {
        if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
            dp[i] = dp[i-1] + 1;
        }
    }

    return accumulate(dp.begin(), dp.end(), 0);
}

int main() {
    vector<int> nums = {1,2,3,4};
    cout << numberOfArithmetricSlices(nums) << endl;
}