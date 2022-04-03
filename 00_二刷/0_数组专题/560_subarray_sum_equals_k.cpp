/* T560:和为 K 的子数组 https://leetcode-cn.com/problems/subarray-sum-equals-k/
 * 思想：
 * 前缀和+哈希
 * 统计前缀和，两前缀和之差为k，则两前缀相差的部分即为和为k的子数组
 * 方法：前缀和+哈希O(n)
 * */

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> prefixs;
    prefixs[0] = 1;// 当prefixSum恰好为k时
    int prefixSum = 0, ans = 0;
    for (int i = 0; i < n; i ++) {
        prefixSum += nums[i];
        if (prefixs.count(prefixSum - k))// 存在另一个prefixSum，二者相差k
            ans += prefixs[prefixSum - k];
        prefixs[prefixSum]++;// 统计次数
    }
    return ans;
}