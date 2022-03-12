/* T739:每日温度 https://leetcode-cn.com/problems/daily-temperatures/
 * 思想：
 * 使用数组存放每个温度对应下标-->有限长的遍历
 * 方法：暴力解法O(n)
 * */

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0), next(101, INT_MAX);

    for (int i = n - 1; i >= 0; i--) {// 从后往前遍历-->保证大于temperatures[i]的最小天数
        int warmerIndex = INT_MAX;
        for (int t = temperatures[i] +1; t <= 100; t++) {// 寻找比当前温度高的下标
            warmerIndex = min(warmerIndex, next[t]);
        }
        if (warmerIndex != INT_MAX)
            ans[i] = warmerIndex - i;
        next[temperatures[i]] = i;// 更新温度对应下标，保证大于temperatures[i]的最小天数
    }

    return ans;
}