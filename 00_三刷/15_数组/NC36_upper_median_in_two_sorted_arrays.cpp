/* NC36 在两个长度相等的排序数组中找到上中位数
 * 原题链接：https://www.nowcoder.com/practice/6fbe70f3a51d44fa9395cfc49694404f?tpId=117&tqId=37808&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3D36%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=36
 * */

class Solution {
public:
    /**
     * find median in two sorted array
     * @param arr1 int整型vector the array1
     * @param arr2 int整型vector the array2
     * @return int整型
     */
    int findMedianinTwoSortedAray(vector<int>& arr1, vector<int>& arr2) {
        // write code here
        int n = arr1.size();// n1==n2

        int cur1 = 0, cur2 = 0;

        for (int i = 1; i < n; i++) {// 比较n-1次
            if (arr1[cur1] < arr2[cur2]) cur1++;// 谁小移动谁
            else cur2++;
        }

        return arr1[cur1] < arr2[cur2] ? arr1[cur1] : arr2[cur2];
    }
};