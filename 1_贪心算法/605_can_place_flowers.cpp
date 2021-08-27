/* leetcode T605:种花问题
 * 原题链接：https://leetcode-cn.com/problems/can-place-flowers/
 * */

#include <stdio.h>
#include <vector>

/* 方法一：贪心
 *
 * 算法思想：
 * 核心思想：
 * 每三个为一组--最小判断单位，逐次推进，对每三个的组合进行判断--只要有连着三个0就可以种下一棵
 * 重点：
 * 边界条件！！！--flowers数组的前一个和后一个元素都默认为0--像{0,0,1}和{1,0,0}都是可以分别在前面和后面种一棵的
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，n为flowers数组的长度
 * 空间复杂度：O(1)，不需额外开销；
 * */

using namespace std;

/*实现方法*/
bool canPlaceFlowers(vector<int> &flowers, int n) {
    int max_flower_num = 0;
    int len = flowers.size();
    // 分别在flowers数组的前面和后面添加一个元素
    flowers.insert(flowers.begin(),0);
    flowers.push_back(0);// 应对flowers[-1]
    int i = 1;// 从flowers[1]开始，flowers[len]结束--x[原来的flowers数组]x

    while (i <= len) {
        // 只要有连着三个0就可以种下一棵
        if (flowers[i-1] == 0 && flowers[i] == 0 && flowers[i+1] == 0) {
            flowers[i] = 1;// 种上了花的地方就要变成1
            max_flower_num++;
        }
        i++;
    }

    return n <= max_flower_num;
}

// 该方法有问题--边界条件不完善
//bool canPlaceFlowers2(vector<int> &flowers,int n) {
//    int max_flower_num = 0;
//
//    // 分别在flowers数组的前面和后面添加一个元素
//    flowers.insert(flowers.begin(),0);
//    flowers.push_back(0);// 应对flowers[-1]
//    int len = flowers.size();
//    int i = 0, j = 1, k = 2;
////    int i = 1;// 从flowers[1]开始，flowers[len]结束--x[原来的flowers数组]x
//    while (i < len && j < len && k < len) {
//        // 三个一组，分情况判断
//        if (flowers[i] == 1 && flowers[j] == 0 && flowers[k] == 0) {
//            flowers[k] = 1;
//            max_flower_num++;
//        }
//        else if (flowers[i] == 0 && flowers[j] == 0 && flowers[k] == 1) {
//            flowers[i] = 1;
//            max_flower_num++;
//        }
//        else if (flowers[i] == 0 && flowers[j] == 0 && flowers[k] == 0) {
//            flowers[j] = 1;
//            max_flower_num++;
//        }
//        i += 1;
//        j += 1;
//        k += 1;
//    }
//
//    return n <= max_flower_num;
//}

/*测试*/
int main() {
    vector<int> flowers = {0,0,1};
    int n = 1;

    if (canPlaceFlowers(flowers, n))
        printf("yes");
    else
        printf("no");
}
