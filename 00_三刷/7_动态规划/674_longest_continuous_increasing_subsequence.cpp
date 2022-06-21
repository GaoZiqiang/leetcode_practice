/* leetcode T674:最长连续递增序列
 * 原题链接：https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
 * */

/* 方法一：一次遍历
 * 算法思想：
 * 以每个元素i为起点，计算以该元素为起点的连续递增的元素的个数(nums[j+1]>nums[j])
 * 并实时更新结果ans
 * for (int i = 0; i < n; i++) {
 *      int tmp = 1;
 *      for (int j = i+1; j < n; j++) {
 *          if (nums[j] > nums[j-1]) tmp++;
 *          else break;
 *      }
 *      ans = max(ans, tmp);// 更新ans
 * }
 *
 * 复杂度分析：
 * 时间复杂度：O(n*n)，最大可达n*n。
 * 空间复杂度：O(1)。
 *
 * 方法二：动态规划
 *
 * 算法思想：
 * 使用dp[i]保存以元素i为终点的连续子序列的长度
 * -->状态转移时，只要nums[i+1]>nums[i]，则dp[i+1]=dp[i]+1即可。
 *
 * 关键点：
 *   1 dp数组初始化，每个元素初始值为1(不同于之前的0，因为每个元素都可以构成一个长度为1的子序列)；
 *   2 使用ans存放结果，对每一个元素i结尾的子序列都要比较。
 *
 * 复杂度分析：
 * 时间复杂度：O(n)。
 * 空间复杂度：O(n)。
 * */


#include <vector>

using namespace std;

// 方法一：一次遍历
int findLengthOfLCIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return n;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int tmp = 1;
        // 遍历i之后比nums[i]大的元素的个数
        for (int j = i+1; j < n; j++) {
            if (nums[j] > nums[j-1]) tmp++;
            else break;
        }
        ans = max(ans, tmp);// 更新ans
    }

    return ans;
}

// 方法二：动态规划
int findLengthOfLCIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return n;

    // dp[i]：以i为结尾的连续递增子序列的长度
    vector<int> dp(n, 1);// 每个dp[i]初始值为1-->即使nums[i]不比前面的任何一个元素大，其nums[i]元素本身仍然能构成长度为1的子序列
    int ans = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i-1]) dp[i] = dp[i-1] + 1;
        // else dp[i] = 1;
        ans = max(ans, dp[i]);// 更新ans
    }

    return ans;
}