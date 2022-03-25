/* leetcode T977:有序数组的平方
 * 原题链接：https://leetcode-cn.com/problems/squares-of-a-sorted-array/
 * */

/* 方法一：双指针法
 *
 * 算法思想：参考https://www.programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html#%E6%9A%B4%E5%8A%9B%E6%8E%92%E5%BA%8F
 * 数组其实是有序的， 只不过负数平方之后可能成为最大数了。
 * 那么数组平方的最大值就在数组的两端，不是最左边就是最右边，不可能是中间。
 * 此时可以考虑双指针法了，i指向起始位置，j指向终止位置。
 * 定义一个新数组result，和A数组一样的大小，让k指向result数组终止位置。
 * 如果A[i] * A[i] < A[j] * A[j] 那么result[k--] = A[j] * A[j]; 。
 * 如果A[i] * A[i] >= A[j] * A[j] 那么result[k--] = A[i] * A[i]; 。
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，
 * 空间复杂度：O(1)。
 * */

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    int k = n - 1;
    int left = 0, right = n - 1;
    while (left <= right) {
        int lsqure = nums[left] * nums[left], rsqure = nums[right] * nums[right];
        if (lsqure < rsqure) {
            res[k--] = rsqure;
            right--;
        }
        else {
            res[k--] = lsqure;
            left++;
        }
    }
    return res;
}