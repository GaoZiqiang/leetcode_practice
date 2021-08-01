/* leetcode T167:两数之和 II - 输入有序数组
 * 原题链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 * */

#include <vector>
#include <stdio.h>

using namespace std;

/* 方法一：二分查找法
 *
 * 整体算法思想如下：
 * 因为该数组为有序数组，我们可以将第一个目标数作为查找序列的起点low，将原数组的最后一个点作为查找序列的终点high，
 * 然后借鉴二分查找的思想，根据numbers[mid]和target的关系逐次调整二分查找的上下界low和high，
 * 直到得到目标点。
 *
 * 注意：
 * 注意将二分查找法应用于该题时涉及到的上下界的灵活变换
 * 原序列中的每个元素都作为起点一次low = i，hight = numbers.size() - 1，mid = (low + hight) / 2
 *
 * 复杂度分析：
 * 时间复杂度：O(nlog n)，序列中的每个数都要遍历一遍，时间复杂度为O(n)，每个二分查找的时间复杂度为O(log n)
 * 空间复杂度：O(1)
 *
 * ***补充：递归算法的时间复杂度计算问题（参考知乎：https://www.zhihu.com/question/63075755）
 * 递归算法的时间复杂度本质上是要看: 递归的次数 * 每次递归中的操作次数
 * */

vector<int> twoSum(vector<int> &numbers, int target) {
    for (int i = 0; i < numbers.size(); i++) {
        /*确定起始点*/
        int low = i, high = numbers.size() - 1;// 根据题目可知，target >= numbers[low]，或者说target满足：target大于等于第一个数
        while (low <= high) {
            /*确定mid*/
            int mid = (low + high) / 2;
            /*根据numbers[mid]和target，调整上下界*/
            if (numbers[mid] == target - numbers[i])
                return {i + 1, mid + 1};
            else if (numbers[mid] < target - numbers[i])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
}

/*测试*/
int main() {
    vector<int> numbers = {2,3,4};
    int target = 6;
    vector<int> res = twoSum(numbers,target);
    printf("answers[1]: %d\n",res[0]);
    printf("answers[2]: %d\n",res[1]);
}