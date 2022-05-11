/* leetcode T376:摆动序列
 * 原题链接：https://leetcode.cn/problems/wiggle-subsequence/
 * */

/* 方法一：贪心
 *
 * 核心思想：
 * 找波峰波谷
 * 每一个波峰波谷都是待选元素
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个元素至多访问一次。
 * 空间复杂度：O(1)。
 * */

#include <vector>

using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n;

    int curDiff = 0, preDiff = 0;
    int ans = 1;

    for (int i = 0; i < n-1; i++) {
        curDiff = nums[i+1] - nums[i];
        if ((curDiff < 0 && preDiff >= 0) || (curDiff > 0 && preDiff <= 0)) {
            ans++;
            preDiff = curDiff;
        }
    }

    return ans;
}