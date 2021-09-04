/* leetcode T435:无重叠区间
 * 原题链接：https://leetcode-cn.com/problems/non-overlapping-intervals/
 * */

#include <vector>
#include <stdio.h>
#include <algorithm>

/* 方法一：贪心
 *
 * 算法思想：
 * 核心思想：
 * 保留尾部元素小的区间-->这样可以保留尽可能大的空间给后续区间-->尽可能保留更多区间-->要移除的区间个数最少
 * 重点：
 * 1 给区间排序
 * 2 用intervals[i][0]与prev(prev为intervals[x][1])进行比较:
 *   if (intervals[i][0] < prev)  ++delete_num;
 *   else  prev = intervals[i][1];
 *
 *
 * 复杂度分析：
 * 时间复杂度：O(nlogn)，排序开销为O(nlogn)，遍历开销为O(n)；
 * 空间复杂度：O(logn)，排序需使用的栈开销；
 * */

using namespace std;

/*删除指定位置的元素*/
vector<vector<int>> removeElement(vector<vector<int>> &intervals, int i) {
    vector<vector<int>>::iterator it = intervals.begin() + i;
    intervals.erase(it);
    printf("intervals size: %d\n",intervals.size());

    return intervals;
}

/*按照区间尾部元素排序*/
int cmpByTail(const vector<int> &x, const vector<int> &y) {
    return x[1] < y[1];
}

/*我的解法--有待优化*/
int eraseOverlapInstervals(vector<vector<int>> &intervals) {
    int len = intervals.size();
    int delete_num = 0;// 删除元素数量
    for (int i = 0; i < intervals.size(); i++) {
        printf("intervals.size():%d\n",intervals.size());
        // 避免多次读取元素，节省开销
        int temp_pre = intervals[i][0], temp_tail = intervals[i][1];
        //printf("intervals[i][0]: %d, intervals[i][1]: %d\n",intervals[i][0], temp_tail = intervals[i][1]);
        for (int j = 0; j < intervals.size(); j++) {
            printf("intervals[j][0]: %d, intervals[j][1]: %d\n",intervals[j][0], temp_tail = intervals[j][1]);
            if (temp_pre >= intervals[j][1] && temp_tail <= intervals[j+1][0])
                break;
            else if (temp_pre >= intervals[j][0] && temp_pre <= intervals[j][1] && temp_tail > intervals[j][1]) {
//                intervals[i] = intervals[j];// 删除intervals[i]或者intervals[j]都可以--伪删除
                removeElement(intervals, i);// 真删除
                delete_num++;
                break;
            } else if (temp_pre >= intervals[j][1] && temp_pre <= intervals[j+1][0] && temp_tail > intervals[j+1][0]) {
//                intervals[i] = intervals[j];// 删除intervals[i]或者intervals[j]都可以--伪删除
                removeElement(intervals, i);// 真删除
                delete_num++;
                break;
            }

        }
    }

    return delete_num;
}

/*官方解法*/
int eraseOverlapInstervals2(vector<vector<int>> &intervals) {
    if (intervals.empty())
        return 0;

    // 按照区间尾部元素排序
    sort(intervals.begin(), intervals.end(), cmpByTail);

    int delete_num = 0, len = intervals.size();;
    int prev = intervals[0][1];// 暂存

    for (int i = 1; i < len; i++) {// 从i=1开始，第一个作为保留
        if (intervals[i][0] < prev)
           ++delete_num;
        else
            prev = intervals[i][1];
    }
    return delete_num;
}

/*测试*/
int main() {
    vector<vector<int>> vec = {{1,2},{2,3},{3,4},{1,3}};
    int delete_num = eraseOverlapInstervals2(vec);
    printf("delete_num: %d\n",delete_num);
}