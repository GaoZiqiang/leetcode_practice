/* T34:在排序数组中查找元素的第一个和最后一个位置 https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * 思路：https://app.yinxiang.com/Home.action?_sourcePage=kyeeqHe6-DniMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=Q1bMCpORWMw3yWPvuidLz-TPR6I9Jhx8&login=true&username=gaoziqianghi%40163.com#n=b17f1868-5267-4182-a727-3c4818a01ecf&s=s3&t=9b8b7b13-7239-446d-8ad5-eddfabb8fa22&ses=4&sh=3&sds=2&
 * 方法：二分查找+线性查找O(logn)
 * */

vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) {
        return {-1, -1};
    }
    // 二分查找target所在的左区间边界
    int left = findLeft(nums, target);
    if (left == -1) {
        return {-1, -1};
    }
    // 线性查找右边界
    int right = left;
    for (; right < nums.size(); right++) {
        if (nums[right] != target) {
            break;
        }
    }

    return {left, right - 1};
}

// 二分查找target所在的左区间边界
int findLeft(vector<int>& nums, int target) {
    int l = 0, h = nums.size() - 1;
    while (l <= h) {
        int m = (l + h) /2;
        if (m == 0 && nums[m] == target) {
            return m;
        } else if (m - 1 >= 0 && nums[m] == target && nums[m-1] < nums[m]) {// 左区间边界
            return m;
        } else if (nums[m] == target){// 继续往左找
            h = m;
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return -1;
}