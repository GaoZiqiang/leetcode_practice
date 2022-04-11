/* leetcode T18:四数之和
 * 原题链接：https://leetcode-cn.com/problems/4sum/
 * */

/* 方法一：for循环+双指针法
 *
 * 算法思想：参考https://programmercarl.com/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.html
 * 关键点：
 * 1 去重
 * 2 双指针while(left < right) 此时l==r不能取 即while (left <= right)
 *
 * 复杂度分析：
 * 时间复杂度：O(n^3)，两层for循环+一个双指针。
 * 空间复杂度：O(1)。
 * */


#include <vector>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> res;
    // 排序
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        // 去重i
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            // 去重j
            if (j > i + 1 && nums[j] == nums[j-1]) {
                continue;
            }
            int newTarget = target - nums[i] - nums[j];
            int l = j + 1, r = n - 1;
            while (l < r) {// l不能等于r l==r-->重复
                if (nums[l] + nums[r] == newTarget) {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    // 去重l r
                    while (l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;
                    l++, r--;
                } else if (nums[l] + nums[r] < newTarget) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }
    return res;
}