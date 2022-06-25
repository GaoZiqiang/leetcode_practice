/* leetcode T1248:统计「优美子数组
 * 原题链接：https://leetcode-cn.com/problems/count-number-of-nice-subarrays/
 * */

/* 方法一：前缀和
 * 算法思想：
 *
 * 关键点：
 * 使用数组odds[i]记录每个元素i处的奇数的个数
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，每个节点只需要遍历一次。
 * 空间复杂度：O(n)，递归-栈空间
 * */


int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> odds(n, 0);
    unordered_map<int, int> prefix;// 包含k个奇数的子数组的个数
    int res = 0;

    prefix[0] = 1;

    for (int i = 0; i < n; i++) {
        // 判断奇偶
        if (i == 0) {
            if (nums[0] % 2) {
                odds[0] = 1;
            }
        } else {
            if (nums[i] % 2) {
                odds[i] += odds[i-1] + 1;
            } else {
                odds[i] = odds[i-1];
            }
        }

        // 查看前缀
        if (prefix.find(odds[i] - k) != prefix.end()) {
            res += prefix[odds[i] - k];
        }

        // 统计
        prefix[odds[i]]++;
    }

    return res;
}

// 我的解法
int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();

    unordered_map<int, int> preOdds;
    preOdds[0] = 1;// 当preOdd恰好为k时
    int preOdd = 0;// 从起点开始的子数组中奇数的总个数
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 == 1) preOdd++;

        if (preOdds.count(preOdd-k)) ans += preOdds[preOdd-k];

        preOdds[preOdd]++;
    }

    return ans;
}