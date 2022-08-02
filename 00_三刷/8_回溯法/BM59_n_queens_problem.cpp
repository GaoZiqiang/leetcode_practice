/* BM59 N皇后问题
 * 原题链接：https://www.nowcoder.com/practice/c76408782512486d91eea181107293b6?tpId=295&tqId=1008753&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 * */


#include <vector>

using namespace std;

class Solution {
public:
    /**
     *
     * @param n int整型 the n
     * @return int整型
     */
    bool isValid(vector<int>& pos, int row, int col) {
        // 判断前面row-1行中的位置[i, pos[i]]是否与当前[row, col]位置同行/同列/对角线
        for (int i = 0; i < row; i++) {
            if (row == i || col == pos[i] || abs(row - i) == abs(col - pos[i])) return false;
        }
        return true;
    }

    void backTracking(int n, int row, vector<int>& pos, int& res) {
        // 所有行都已经确定位置--一种排列方案
        if (row >= n) {
            res++;// 一种排列方案
            return;
        }

        // 判断第row行第i列是否符合条件
        for (int i = 0; i < n; i++) {
            if (isValid(pos, row, i)) {// 验证[row, i]位置的合法性
                // 确认第row行第i列
                pos[row] = i;
                // 继续确定下一行的位置
                backTracking(n, row + 1, pos, res);
            }
        }
    }

    int Nqueen(int n) {
        // write code here
        int res = 0;
        vector<int> pos(n, 0);// 记录行列号 数组序号为行号 元素值为列号
        backTracking(n, 0, pos, res);

        return res;
    }
};