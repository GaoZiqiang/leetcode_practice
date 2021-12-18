/* leetcode T70:爬楼梯
 * 原题链接：https://leetcode-cn.com/problems/climbing-stairs/
 * */

/* 方法一：动态规划--基于递归
 *
 * 算法思想：
 * 核心：
 * 根据题目已知，每次可以走一层或两层，因此，每次都有两种选择-->由此可以通过递归计算总的可能方案次数
 * res = sum(n - 1)(第一次走一层) + sum(n - 2)(或者第一次走两层)
 *
 * 递归优化：
 * 本题中递归的时间复杂度为O(n^2)
 * 通过观察递归二叉树我们可以看到，每一个子树中都存在重复的/相同的子树，因此可以通过暂存子树的求和结果，
 * 在遇到相同子树时就不用再次递归计算该子树的组合情况了-->这样就能够减少递归操作次数，从而降低时间复杂度
 *
 * 两个点：
 * 1 使用unordered_map而不用map的原因：
 * unordered_map为无序map，减少了排序的时间开销
 * 2 unordered_map使用emplace而不用insert的原因
 * emplace方法节省内存开销
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，通过递归优化，实际上只需要完整的构造/遍历完一棵子树就可以了，这棵树有n层，每层的工作量为1。
 * 空间复杂度：O(n)，unordered_map包含n个pair对。
 *
 * 参考讲解：https://leetcode-cn.com/problems/climbing-stairs/solution/yuan-lai-hui-pa-lou-ti-de-zheng-que-zi-s-pjez/
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