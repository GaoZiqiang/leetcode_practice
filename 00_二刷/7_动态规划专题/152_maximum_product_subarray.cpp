/* T152:乘积最大子数组 https://leetcode-cn.com/problems/maximum-product-subarray/
 * 思想：
 * 方法：动态规划O(n)
 * */

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];
    int max_ = 1, min_ = 1, ans = nums[0];
    for (int i = 0; i < n; i++) {
        if (nums[i] < 0)
            swap(max_, min_);
        max_ = max(max_ * nums[i], nums[i]);
        min_ = min(min_ * nums[i], nums[i]);
        ans = max(max_, ans);
    }
    return ans;
}