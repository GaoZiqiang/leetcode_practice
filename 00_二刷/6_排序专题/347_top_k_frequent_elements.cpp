/* T347:前 K 个高频元素 https://leetcode-cn.com/problems/top-k-frequent-elements/
 * 思想：哈希表+堆排序
 * 先使用哈希表记录每个元素出现的次数，
 * 然后使用堆排序对元素出现的次数进行排序
 * 方法：堆排序(nlogn)
 * */

// 比较函数
static bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second > p2.second;
}
// 实现方法
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    for (auto& x : nums)
        hash[x]++;
    // 定义小顶堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
    for (auto& [num, cnt] : hash) {
        if (q.size() == k) {
            if (cnt > q.top().second) {
                q.pop();
                q.push(make_pair(num, cnt));
            }
        } else {// q.size() < k 不会出现q.size() > k
            q.push(make_pair(num, cnt));
        }
    }
    // 堆中元素依次出堆 存入结果ans
    vector<int> ans;
    while (!q.empty()) {
        ans.push_back(q.top().first);
        q.pop();
    }
    return ans;
}