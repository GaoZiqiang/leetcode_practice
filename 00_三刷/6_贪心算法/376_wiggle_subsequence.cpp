/* leetcode T376:摆动序列
 * 原题链接：https://leetcode.cn/problems/wiggle-subsequence/
 * */

/* 方法一：贪心
 *
 * 核心思想：参考https://www.programmercarl.com/0376.%E6%91%86%E5%8A%A8%E5%BA%8F%E5%88%97.html#%E6%80%9D%E8%B7%AF2-%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92
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