/* leetcode T724:寻找数组的中心下标
 * 原题链接：https://leetcode-cn.com/problems/find-pivot-index/
 * */

/* 方法一：前缀和
 * 算法思想：
 * 左侧和==右侧和 返回
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O(1)。
 *
 * 方法二：两次遍历
 * 算法思想：
 * 保存每个元素的左边和和右边和
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O(n)。
 * */


int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // for (auto& num : nums)
    //     sum += num;

    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        left += nums[i];
        right = sum - left;
        if (left - nums[i] == right) {// 左和==右和
            return i;
        }
    }

    return -1;
}

// 我的方法：两次遍历
int pivotIndex(vector<int>& nums) {
    int n = nums.size();

    vector<int> dpLeft(n, 0);
    vector<int> dpRight(n, 0);

    dpLeft[0] = 0;
    // 左->右
    for (int i = 1; i < n; i++) {
        dpLeft[i] = dpLeft[i-1] + nums[i-1];
    }

    // 右->左
    dpRight[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        dpRight[i] = dpRight[i+1] + nums[i+1];
    }

    // 比较
    for (int i = 0; i < n; i++) {
        if (dpLeft[i] == dpRight[i]) return i;
    }

    return -1;
}

// 小优化
int pivotIndex(vector<int>& nums) {
    int n = nums.size();

    vector<int> dpLeft(n, 0);
    vector<int> dpRight(n, 0);

    // 先从右到左
    // 右->左
    dpRight[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        dpRight[i] = dpRight[i+1] + nums[i+1];
    }

    dpLeft[0] = 0;
    if (dpLeft[0] == dpRight[0]) return 0;// 易漏
    // 左->右
    for (int i = 1; i < n; i++) {
        dpLeft[i] = dpLeft[i-1] + nums[i-1];
        if (dpLeft[i] == dpRight[i]) return i;// 比较左右
    }

    return -1;
}

int pivotIndex(vector<int>& nums) {
    int n = nums.size();

    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    int preSum = 0;
    for (int i = 0; i < n; i++) {
        preSum += nums[i];
        if (preSum-nums[i] == totalSum - preSum) return i;
    }

    return -1;
}