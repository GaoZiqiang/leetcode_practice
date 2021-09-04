#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

vector<vector<int>> removeElement(vector<vector<int>> &intervals, int i) {
    vector<vector<int>>::iterator it = intervals.begin() + i;
    intervals.erase(it);
    printf("intervals size: %d\n",intervals.size());

    return intervals;
}

int eraseOverlapInstervals(vector<vector<int>> &intervals) {
//    else if (temp_pre == intervals[j][0] && temp_tail =< intervals[j+1][0]) {
//        intervals[i] = intervals[j]// 删除intervals[i]或者intervals[j]都可以--伪删除
//        delete_num++;
//    }
    int len = intervals.size();
    int delete_num = 0;// 删除元素数量
    for (int i = 0; i < intervals.size(); i++) {
        // 避免多次读取元素，节省开销
        int temp_pre = intervals[i][0], temp_tail = intervals[i][1];
        //printf("intervals[i][0]: %d, intervals[i][1]: %d\n",intervals[i][0], temp_tail = intervals[i][1]);
        for (int j = 0; j < intervals.size(); j++) {
            printf("intervals[j][0]: %d, intervals[j][1]: %d\n",intervals[j][0], temp_tail = intervals[j][1]);
            if (temp_pre >= intervals[j][1] && temp_tail <= intervals[j+1][0])
                continue;
            else if (temp_pre >= intervals[j][0] && temp_pre <= intervals[j][1] && temp_tail > intervals[j][1]) {
//                intervals[i] = intervals[j];// 删除intervals[i]或者intervals[j]都可以--伪删除
                removeElement(intervals, i);// 真删除
                delete_num++;
            } else if (temp_pre >= intervals[j][1] && temp_pre <= intervals[j+1][0] && temp_tail > intervals[j+1][0]) {
//                intervals[i] = intervals[j];// 删除intervals[i]或者intervals[j]都可以--伪删除
                removeElement(intervals, i);// 真删除
                delete_num++;
            }

        }
    }

    return delete_num;
}

int main() {
    vector<vector<int>> vec = {{1,2},{1,2},{1,2}};
//    vector<vector<int>> vec = {{1,2},{3,4}};

    //printf("10:%d\n",vec[10]);
    printf("size:%d\n",vec.size());
    for (int i = 0; i < vec.size(); i++)
        printf("vec[0]: %d, vec[1]: %d\n",vec[i][0],vec[i][1]);

    //vector<vector<int>> result = removeElement(vec,10);
    int delete_num = eraseOverlapInstervals(vec);
    printf("delete_num: %d\n",delete_num);
//    printf("size:%d\n",result.size());
    printf("size:%d\n",vec.size());
    for (int i = 0; i < vec.size(); i++)
        printf("vec[0]: %d, vec[1]: %d\n",vec[i][0],vec[i][1]);
}