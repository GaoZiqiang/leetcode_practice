/* leetcode T167:两数之和 II - 输入有序数组
 * 原题链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 * */

#include <vector>
#include <stdio.h>

using namespace std;

/* 方法一：二分查找法
 * 方法的核心就是尽量减少查找/比较的次数--本质是一个查找问题
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
 * */

vector<int> twoSum(vector<int> &numbers, int target) {
    /*遍历n次*/
    for (int i = 0; i < numbers.size(); i++) {
        /*确定起始点*/
        int low = i, high = numbers.size() - 1;// 根据题目可知，target >= numbers[low]，或者说target满足：target大于等于第一个数
        /*遍历logn次*/
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

/* 方法二：双指针法
 *
 * 方法的核心就是尽量减少查找/比较的次数--本质是一个查找问题
 *
 * 整体算法思想如下：
 * 初始时两个指针分别指向第一个元素位置和最后一个元素的位置。每次计算两个指针指向的两个元素之和，
 * 并和目标值比较。如果两个元素之和等于目标值，则发现了唯一解。如果两个元素之和小于目标值，则将左侧指针右移一位。
 * 如果两个元素之和大于目标值，则将右侧指针左移一位。移动指针之后，重复上述操作，直到找到答案。
 *
 * 复杂度分析：
 * 与二分法相比较，双指针法的单次查找次数为n，二分法为log n，但双指针法没有外面的for循环。
 * 时间复杂度：O(n)，平均查找次数应该为n/2，最多需要查找n次。一端不动，另一端从一头移动到另一头。
 * 空间复杂度：O(1)
 * */
vector<int> twoSum2(vector<int> numbers,int target) {
    int low = 0, high = numbers.size() - 1;

    while (low < high) {
        if (numbers[low] + numbers[high] > target)
            high -= 1;// 右指针左移
        else if (numbers[low] + numbers[high] < target)
            low += 1;// 左指针右移
        else
            return {low + 1, high + 1};
    }
}

/*测试*/
int main() {
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    vector<int> res = twoSum(numbers,target);
    printf("answers[1]: %d\n",res[0]);
    printf("answers[2]: %d\n",res[1]);

    // 测试方法二
    vector<int> res2 = twoSum2(numbers,target);
    printf("answers[1]: %d\n",res2[0]);
    printf("answers[2]: %d\n",res2[1]);
}