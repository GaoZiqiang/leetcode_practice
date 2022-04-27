/* T739:每日温度 https://leetcode-cn.com/problems/daily-temperatures/
 * 方法一：暴力求解
 * 思想：
 * 使用数组存放每个温度对应下标-->有限长的遍历
 * 方法：暴力解法O(n)
 *
 * 方法二：单调栈
 * 时间复杂度：O(n)
 * */

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0), next(101, INT_MAX);

    for (int i = n - 1; i >= 0; i--) {// 从后往前遍历-->保证大于temperatures[i]的最小天数
        int warmerIndex = INT_MAX;
        for (int t = temperatures[i] + 1; t <= 100; t++) {// 寻找比当前温度高的下标
            warmerIndex = min(warmerIndex, next[t]);
        }
        if (warmerIndex != INT_MAX)
            ans[i] = warmerIndex - i;
        next[temperatures[i]] = i;// 更新温度对应下标，保证大于temperatures[i]的最小天数
    }

    return ans;
}

#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0), temps(101, INT_MAX);

    for (int i = n - 1; i >= 0; i--) {
        int warmerPos = INT_MAX;
        for (int t = temperatures[i] + 1; t <= 100; t++) {// 遍历温度大于temperatures[i]的temp数组
            warmerPos = min(warmerPos, temps[t]);// 温度大于temperatures[i]的最小index
        }
        if (warmerPos != INT_MAX)
            res[i] = warmerPos - i;

        temps[temperatures[i]] = i;// 更新temps数组 每个温度的index为最小
    }

    return res;
}

// 方法二：单调栈
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<int> stack;
    vector<int> answer(n, 0);

    for (int i = 0; i < n; i++) {
        while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {// 比当前元素temperatures[i]小的栈内元素依次出栈
            int index = stack.top();
            answer[index] = i - index;// 存入answer
            stack.pop();
        }
        stack.push(i);// 新元素入栈
    }

    return answer;
}