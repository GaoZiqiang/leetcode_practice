/* T15:三数之和 https://leetcode-cn.com/problems/3sum/
 * 思路：b站-https://www.bilibili.com/video/av550661892?from=search&seid=12294664296196362082&spm_id_from=333.337.0.0
 * 方法：双指针法O(n*n)
 * */

vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) {
        return {};
    }
    vector<vector<int>> res;
    // 先进行排序
    sort(nums.begin(), nums.end());
    // 双指针
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        // 关键点一
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int oth = -nums[i];
        int left = i + 1, right = n - 1;
        while (left < right) {
            if (nums[left] + nums[right] == oth) {
                res.push_back({nums[i], nums[left], nums[right]});
                // 关键点二
                while (left < right && nums[left] == nums[left+1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right-1]) {
                    right--;
                }
                left++, right--;
            } else if (nums[left] + nums[right] > oth) {
                right--;
            } else {
                left++;
            }
        }
    }
    return res;
}