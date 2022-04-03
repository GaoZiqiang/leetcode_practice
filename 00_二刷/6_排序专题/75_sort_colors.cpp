/* T75:颜色分类 https://leetcode-cn.com/problems/sort-colors/
 * 思路：基于快速排序的算法思想--分为两次
 * 第一次先将元素分为0和{1,2}两类
 * 然后再将1和2分类
 * 方法：双指针O(n) O(2n)
 * */

void sortColors(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    // 先区分0和{1,2}两类元素
    while (l <= r) {
        while (l <= r && nums[l] == 0) l++;
        while (l <= r && nums[r] > 0) r--;
        if (l > r) break;
        swap(nums[l], nums[r]);
        l++, r--;
    }

    // 再区分1和2
    r = nums.size() - 1;
    while (l <= r) {
        while (l <= r && nums[l] == 1) l++;
        while (l <= r && nums[r] == 2) r--;
        if (l > r) break;
        swap(nums[l],nums[r]);
        l++, r--;
    }
    return;
}