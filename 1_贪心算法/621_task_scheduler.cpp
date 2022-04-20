/* leetcode T621:任务调度器
 * 原题链接：https://leetcode-cn.com/problems/task-scheduler/
 * */

/* 方法一：基于桶思想
 *
 * 算法思想：参考https://leetcode-cn.com/problems/task-scheduler/solution/tong-zi-by-popopop/
 *
 * 复杂度分析：
 * 时间复杂度：O(nlogn)，排序时间复杂度。
 * 空间复杂度：O(1)。
 * */

int leastInterval(vector<char>& tasks, int n) {
    int len = tasks.size();
    vector<int> task(26);// 记录每种任务的个数

    // 统计每种任务的个数
    for (auto& t : tasks) ++task[t - 'A'];

    // 排序
    std::sort(task.begin(), task.end(), [](int& x, int& y) {return x > y;});

    // 统计与最大任务数量相同的任务种数 并列任务个数--最后一个桶子的任务数
    int i = 0, cnt = 1;
    while (++i < 26 && task[i] == task[0]) cnt++;

    return max(len, (task[0] - 1) * (n + 1) + cnt);
}