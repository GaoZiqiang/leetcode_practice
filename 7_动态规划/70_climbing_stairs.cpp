/* leetcode T70:爬楼梯
 * 原题链接：https://leetcode-cn.com/problems/climbing-stairs/
 * */

/* 方法一：动态规划--基于递归
 *
 * 算法思想：
 * 对于第i层，可以有两种方法/路径到达第i层：
 * 第一：上一步一下走两个台阶到达第i层；-->而这种情况有dp[i-2]种方案
 * 第二：上一步一下走一个台阶到达第i层。-->dp[i-1]
 * 共有dp[i-2] + dp[i-1]方案
 *
 * 复杂度分析：
 * 时间复杂度：O(n)；
 * 空间复杂度：O(n)。
 * */


// 实现方法1--从上到下
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    unordered_map<int, int> sum_map;
    int climbStairs(int n) {
        // 递归终止条件
        if (1 == n) return 1;
        if (2 == n) return 2;
        // 在map中查找
        auto it = sum_map.find(n);
        if (it != sum_map.end())
            return it->second;
        int sum = climbStairs(n - 1) + climbStairs(n - 2);
        // 存入map
        sum_map.emplace(pair<int, int>(n, sum));
        return sum;
    }
};

// 实现方法2
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n+1, 1);
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// 实现方法3--对动态规划进行空间压缩
// 因为 dp[i] 只与 dp[i-1] 和 dp[i-2] 有关,因此
// 可以只用两个变量来存储 dp[i-1] 和 dp[i-2],使得原来的 O(n) 空间复杂度优化为 O(1) 复杂度。
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int pre2 = 1, pre1 = 2, cur;
        for (int i = 2; i < n; ++i) {
            cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};

// 利用完全背包思想求解
int climbStairs(int n) {
    if (n < 3) {
        return n;
    }
    vector<int> dp(n+1);
    int steps[2] = {1, 2};
    dp[0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= 2; i++) {
            if (j >= i) {
                dp[j] += dp[j-steps[i-1]];
            }
        }
    }
    return dp[n];
}