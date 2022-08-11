/* BM87 合并两个有序的数组
 * 原题链接：https://www.nowcoder.com/practice/89865d4375634fc484f3a24b7fe65665?tpId=295&tqId=658&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 * */

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) A[k--] = A[i--];
            else A[k--] = B[j--];
        }

        if (i < 0) {
            while (j >= 0) A[k--] = B[j--];
        }

        return;
    }
};