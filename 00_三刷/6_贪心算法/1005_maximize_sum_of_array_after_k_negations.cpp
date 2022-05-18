/* T1005:K次取反后最大化的数组和 https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
 *
 * 方法一：贪心算法
 *
 * 算法思想：
 * 贪心，局部最优：为负且绝对值最大的数优先取负-->数组中元素值最大-->数组元素和最大-->全局最优
 * 若将所有负数全部取负之后，k仍然大于0
 * -->对绝对值最小的数(正数)循环取负
 *
 * 关键点：
 * 对某个数循环取k次负<==>取决于k的奇偶
 * if (k % 2 == 1) nums[n-1] = -nums[n-1];
 *
 * 时间复杂度：O(nlogn)，排序时间复杂度。
 * 空间复杂度：O(1)。
 * */

#include <vector>

using namespace std;

// 需为static函数-->sort为外部函数，没有this指针，不能使用类内部非static函数
static bool cmp(int x, int y) {
    return abs(x) > abs(y);
}

int largestSumAfterKNegations(vector<int>& nums, int k) {
    int n = nums.size();
    // 按绝对值大小排序
    sort(nums.begin(), nums.end(), cmp);

    for (int i = 0; i < n; i++) {
        // 小于0且绝对值最大的
        if (nums[i] < 0 && k > 0) nums[i] = -nums[i];
    }
    // k仍大于0
    // 对绝对值最小的数取负
    if (k % 2 == 1) nums[n-1] = -nums[n-1];

    return accumulate(nums.begin(), nums.end(), 0);// 返回数组和
}