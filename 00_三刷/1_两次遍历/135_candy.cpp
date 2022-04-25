/* leetcode T135:分发糖果
 * 原题链接：https://leetcode-cn.com/problems/candy/
 * */

/* 方法一：两次遍历
 *
 * 核心思想：参考https://blog.csdn.net/qq_39678022/article/details/111771237
 * 1 第一遍从左往右遍历，保证每个孩子的糖数left[i]比左边大；
 * 2 第二遍从右往左遍历，保证每个孩子的糖数right[i]比右边大
 * 3 每个孩子的糖数取max(left[i], right[i])
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，两次遍历。
 * 空间复杂度：O(n)，两个数组。
 * */

#include <vector>

using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left(n, 1), right(n, 1);
    int res = 0;

    // 从左往右遍历
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
    }

    // 从右往左遍历
    for (int j = n - 2; j >= 0; j--) {
        if (ratings[j] > ratings[j+1]) right[j] = right[j+1] + 1;
    }

    // 计算求和
    for (int k = 0; k < n; k++) res += max(left[k], right[k]);

    return res;
}

// 空间优化
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);

        for(int i=1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])left[i] = left[i-1]+1;
        }

        int ret = left[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i] > ratings[i+1])left[i] = max(left[i], left[i+1]+1);
            ret += left[i];
        }

        return ret;
    }
};
