/* leetcode T605:种花问题
 * 原题链接：https://leetcode-cn.com/problems/can-place-flowers/
 * */

#include <stdio.h>
#include <vector>

/* 方法一：贪心
 *
 * 算法思想：
 * 核心思想：
 * 每三个为一组--最小判断单位，逐次推进，对每三个的组合进行判断
 * 注意：
 * 改种方法存在一个弊端--如果最后一个元素为1，则需要另作判断--max_flower_num要减1。
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，n为flowers数组的长度
 * 空间复杂度：O(1)，不需额外开销；
 * */

using namespace std;

int canPlaceFlowers(vector<int> flowers,int n) {
    int max_flower_num = 0;
    int i = 0, j = 1, k = 2;
    int len = flowers.size();
    while (i < len && j < len && k < len) {
        // 三个一组，分情况判断
        if (flowers[i] == 1 && flowers[j] == 0 && flowers[k] == 0) {
            flowers[k] = 1;
            max_flower_num++;
        }
        else if (flowers[i] == 0 && flowers[j] == 0 && flowers[k] == 1) {
            flowers[i] = 1;
            max_flower_num++;
        }
        else if (flowers[i] == 0 && flowers[j] == 0 && flowers[k] == 0) {
            flowers[j] = 1;
            max_flower_num++;
        }
        i++;
        j++;
        k++;
    }

    // 考虑到flowers数组最后一个元素为1这种情况
    // 0 0 0 1或者1 0 0 1或者 0 0 1 1
    if (flowers[j-1] == 1 && flowers[k-1] == 1) {
        flowers[j-1] = 0;
        max_flower_num--;
    }

    return n <= max_flower_num;
}

int main() {
    vector<int> flowers = {1,0,0,0,0,0,1};
    int n = 2;
    if (canPlaceFlowers(flowers, n))
        printf("yes");
    else
        printf("no");
}