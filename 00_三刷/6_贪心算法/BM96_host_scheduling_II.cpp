/* BM96 主持人调度（二）
 * 原题链接：https://www.nowcoder.com/practice/4edf6e6d01554870a12f218c94e8a299?tpId=295&tqId=1267319&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 * 注意：该题不同于leetcode T56合并区间 计算重叠区间个数
 * 本题目主持人可以重复利用，只要时间上不冲突
 * */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算成功举办活动需要多少名主持人
     * @param n int整型 有n个活动
     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
     * @return int整型
     */
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
    }

    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
        // write code here

        vector<int> start;
        vector<int> end;

        for (int i = 0; i < n; i++) {
            start.push_back(startEnd[i][0]);
            end.push_back(startEnd[i][1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int ans = 0;
        int j = 0;// 保留上一场主持人所在的活动id
        for (int i = 0; i < n; i++) {
            // 新开始的节目大于上一场节目结束的时间-->不用换主持人
            if (start[i] >= end[j]) j++;
            else ans++;
        }

        return ans;
    }
};