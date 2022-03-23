/* leetcode T287:寻找重复数
 * 原题链接：https://leetcode-cn.com/problems/find-the-duplicate-number/
 * */

/* 方法一：快慢指针法
 *
 * 关键点：
 * 1 nums[i]元素值就是下一个元素的索引
 * slow = nums[slow]// nums[i]元素值就是下一个元素的索引
 * fast = nums[fast]
 *
 * 2 return slow/fast// 这里的slow和fast已经是nums[i]元素值
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，
 * 空间复杂度：O(1)，递归所需空间，为树的高度。
 * */

int findDuplicate(vector<int>& nums) {
    if (nums.empty())
        return -1;
    int fast = 0, slow = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    fast = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;// nums[slow]?
}