/* leetcode T27:移除元素
 * 原题链接：https://leetcode-cn.com/problems/remove-element/
 * */

/* 方法一：双指针法
 *
 * 算法思想：
 * 核心思想就是数组的元素删除操作的原理：
 * 将待删除元素后面的元素依次移动到待删除元素处。
 *
 * 使用双指针slow和fast，fast为slow赋值，
 * 当nums元素不为val时，slow和fast同步前进，当遇到val时，slow暂停，fast前进
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，
 * 空间复杂度：O(1)。
 * */

int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
        if (val != nums[fast]) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}