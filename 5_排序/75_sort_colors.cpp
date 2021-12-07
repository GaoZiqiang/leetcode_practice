/* leetcode T75:颜色分类
 * 原题链接：https://leetcode-cn.com/problems/sort-colors/
 * */

#include <stdio.h>
#include <malloc.h>

/* 方法一：单指针
 *
 * 算法思想：
 * 进行两次调整，第一次将0调整到序列的前面，其二次将1调整到前面（0的后面）
 * 关键点一：将后续序列中满足nums[i]==0/1的元素与nums[head]进行交换
 * 关键点二：使用head指针标记0/1后一个元素所在的位置
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，O(2n)，进行两次遍历。
 * 空间复杂度：O(1)，原地操作。
 *
 * 方法二：双指针
 * 参考：https://leetcode-cn.com/problems/sort-colors/solution/yan-se-fen-lei-by-leetcode-solution/
 * */

// 方法一
class Solution {
public:
    static void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int head = 0;
        // 第一遍调整，将0调整到序列前面
        for (int i = 0; i <len; i ++ ) {
            if (0 == nums[i]) {
                swap(nums[head], nums[i]);
                head++;
            }
        }
        // 第一遍调整，将0调整到序列前面--1后面
        for (int i = head; i < len; i++) {// 注意此时从head开始
            if (1 == nums[i]) {
                swap(nums[head], nums[i]);
                head++;
            }
        }
    }
};

// 方法二
class Solution {
public:
    static void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (1 == nums[i]) {
                swap(nums[p1], nums[i]);
                p1++;
            } else if (0 == nums[i]) {
                swap(nums[p0], nums[i]);
                if (p0 < p1)
                    swap(nums[p1], nums[i]);
                p0++, p1++;
            }
        }
    }
};