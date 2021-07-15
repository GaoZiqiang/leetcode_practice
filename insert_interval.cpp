/* leetcode T56:Insert Interval(合并区间)
 * 原题链接：https://leetcode-cn.com/problems/merge-intervals/
 *
 * 分析：
 * 设想：如果我们按照区间的左端点排序，那么在排完序的列表中，可以合并的区间一定是连续的。
 * 因此：
 * 我们用数组 merged 存储最终的答案。
 * 首先，我们将列表中的区间按照左端点升序排序。然后我们将第一个区间加入 merged 数组中，并按顺序依次考虑之后的每个区间：
 * 如果当前区间的左端点在数组 merged 中最后一个区间的右端点之后，那么它们不会重合，我们可以直接将这个区间加入数组 merged 的末尾；
 * 否则，它们重合，我们需要用当前区间的右端点更新数组 merged 中最后一个区间的右端点，将其置为二者的较大值。
 *
 * 复杂度分析：
 * 时间复杂度：
 * O(n log n)：主要时间开销为排序的开销，排序开销为O(n log n)。
 * 空间复杂度：
 * O(log n)：排序所需要的额外空间。
 * */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> & intervals) {
        if (intervals.size() == 0) {
            return {};
        }

        /*将列表中的区间按照左端点升序排序*/
        /*先按左端点排序，然后按右端点排序*/
        sort(intervals.begin(),intervals.end());// 归并排序？基数排序
        vector<vector<int>> merged;

        for (int i = 0; i < intervals.size(); ++i) {
            /*L R分别为当前区间的左端点和右端点*/
            int L = intervals[i][0], R = intervals[i][1];
            /*如果列表为空，或者当前区间与上一区间不重合，直接添加*/
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }else {
                /*否则，将当前区间与上一区间合并*/
                merged.back()[1] = max(merged.back()[1],R);// 合并后的区间的左端点认为上一区间的有端点，有端点为两个区间右端点的最大值
            }
        }

        return merged;
    }
};

/*测试*/
int main() {
    Solution *solution = new Solution();
    /*待输入intervals*/
    vector<vector<int>> intervals = {{1,4},{4,5}};

    vector<vector<int>> result;
    result = solution->merge(intervals);

    cout << "result[0][0]: " << result[0][0] << endl;
    cout << "result[0][1]: " << result[0][1] << endl;


}
