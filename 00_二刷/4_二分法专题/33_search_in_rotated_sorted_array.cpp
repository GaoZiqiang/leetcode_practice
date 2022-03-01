/* T33:搜索旋转排序数组 https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * 思路：https://app.yinxiang.com/Home.action?_sourcePage=kyeeqHe6-DniMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=Q1bMCpORWMw3yWPvuidLz-TPR6I9Jhx8&login=true&username=gaoziqianghi%40163.com#n=b17f1868-5267-4182-a727-3c4818a01ecf&s=s3&t=9b8b7b13-7239-446d-8ad5-eddfabb8fa22&ses=4&sh=3&sds=2&
 * 方法：快慢指针O(n)
 * */

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (target == nums[mid]) return mid;
        if (nums[0] <= nums[mid]) {// 左侧有序
            if (target >= nums[0] && target < nums[mid]) {
                high = mid - 1;// target在左侧
            } else {
                low = mid + 1;
            }
        } else {// 右侧有序
            if (target > nums[mid] && target <= nums[n-1]) {
                low = mid + 1;// target在右侧
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}