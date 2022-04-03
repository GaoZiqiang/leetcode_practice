/* T56:合并区间 https://leetcode-cn.com/problems/merge-intervals/
 * 思路：https://app.yinxiang.com/Home.action?_sourcePage=kyeeqHe6-DniMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=Q1bMCpORWMw3yWPvuidLz-TPR6I9Jhx8&login=true&username=gaoziqianghi%40163.com#n=646720e8-79da-4663-aa13-c803e7636c60&s=s3&t=9b8b7b13-7239-446d-8ad5-eddfabb8fa22&ses=4&sh=3&sds=5&
 * 方法：排序O(nlgn)主要为排序的开销
 * */

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int n = intervals.size();
    for (int i = 0; i < n; i++) {
        int pre = intervals[i][0], post = intervals[i][1];
        if (ans.empty() || pre > ans.back()[1]) {// 不重叠
            ans.push_back(intervals[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], post);// 存在重叠
        }
    }
    return ans;
}