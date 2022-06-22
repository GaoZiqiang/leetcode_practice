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

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> sum(n, 0);
    unordered_map<int, int> map;// map存放每个前缀和出现的次数
    int res = 0;

    sum[0] = nums[0];
    map[sum[0]] = 1;

    if (sum[0] == k) {
        res +=  map[sum[0]];
    }

    for (int i = 1; i < n; i++) {
        sum[i] = sum[i-1] + nums[i];

        // sum[i]恰好为target/k
        if (sum[i] == k) {
            res++;
        }

        if (map.find(sum[i] - k) != map.end()) {
            res += map[sum[i] - k];
        }
        map[sum[i]]++;
    }

    return res;
}

// 改进1
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> sum(n, 0);
    unordered_map<int, int> map;// map存放每个前缀和出现的次数
    int res = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            sum[i] = nums[i];
        }   else {
            sum[i] = sum[i-1] + nums[i];
        }

        // sum[i]恰好为target/k
        if (sum[i] == k) {
            res++;
        }

        if (map.find(sum[i] - k) != map.end()) {
            res += map[sum[i] - k];
        }
        map[sum[i]]++;
    }

    return res;
}

// 改进2 sum替代sum数组
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    // vector<int> sum(n, 0);
    int sum = 0;
    unordered_map<int, int> map;// map存放每个前缀和出现的次数
    int res = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];

        // sum恰好为target/k
        if (sum == k) {
            res++;
        }

        if (map.find(sum - k) != map.end()) {
            res += map[sum - k];
        }
        map[sum]++;
    }

    return res;
}

// 改进3 map添加0
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    // vector<int> sum(n, 0);
    int sum = 0;
    unordered_map<int, int> map;// map存放每个前缀和出现的次数
    int res = 0;

    // sum恰好为target/k 此时sum - k == 0
    map[0] = 1;

    for (int i = 0; i < n; i++) {
        sum += nums[i];

        // sum恰好为target/k
        // if (sum == k) {
        //     res++;
        // }

        if (map.find(sum - k) != map.end()) {
            res += map[sum - k];
        }

        map[sum]++;
    }

    return res;
}

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();

    unordered_map<int, int> prefixSums;

    prefixSums[0] = 1;
    int preSum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        preSum += nums[i];

        if (prefixSums.count(preSum-k))
            ans += prefixSums[preSum-k];

        prefixSums[preSum]++;
    }

    return ans;
}

// 变式：找和为k的最长的连续子数组
int maxlenEqualK(vector<int>& arr, int k) {
    int n = arr.size();

    unordered_map<int, int> prefixSums;
    prefixSums[0] = -1;
    int preSum = 0, ans = -1;

    for (int i = 0; i < n; i++) {
        preSum += arr[i];

        if (prefixSums.count(preSum-k)) {
            ans = max(ans, i-prefixSums[preSum-k]);
        }

        if (prefixSums.count(preSum)) {
            // 保存最小的i
            prefixSums[preSum] = min(prefixSums[preSum], i);
        } else {
            prefixSums[preSum] = i;
        }
        // prefixSums[preSum] = i;
    }

    return ans;
}