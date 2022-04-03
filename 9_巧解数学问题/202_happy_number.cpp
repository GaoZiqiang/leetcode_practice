/* leetcode T202:快乐数
 * 原题链接：https://leetcode-cn.com/problems/happy-number/
 * */

/* 方法一：哈希法
 *
 * 算法思想：
 * 1 数位分离，求平方和
 * 2 判断是否出现循环或者sum为1
 *
 * 复杂度分析：
 * 时间复杂度：O(logn)，每个数字包含的位数。
 * 空间复杂度：O(n)，hash_set。
 * */

#include <iostream>
#include <hash_set>

using namespace std;

bool isHappy(int n) {
    __gnu_cxx::hash_set<int> sums;// 使用hast_set存放sum值，用于判断循环
    int tmp = n;
    int sum = 0;
    while (1) {
        // 逐位求平方和
        sum += (tmp % 10) * (tmp % 10);
        tmp = tmp / 10;
        // 判断下一个sum值
        if (0 == tmp) {
            if (sums.find(sum) != sums.end())// 存在重复元素
                return false;
            sums.insert(sum);
            tmp = sum;
            if (1 == sum) {
                return true;
            }
            sum = 0;// sum置0
        }
    }
    cout << "sum = " << sum << endl;
    return 1 == sum;
}

// 实现二
int countSum(int n) {
    int sum = 0;
    sum = 0;
    int yu = 0;
    while (n != 0) {
        yu = n % 10;
        n = n / 10;
        sum += yu * yu;
    }
    return sum;
}

bool isHappy(int n) {
    int sum = 0;
    unordered_set<int> sums;// 统计出现的sum

    while (true) {
        sum = countSum(n);
        if (sum == 1)// 满足条件-->结束while
            return true;

        // 判断
        if (sums.find(sum) != sums.end())// 已经出现-->存在循环
            return false;
        sums.insert(sum);

        // 计算新一轮sum
        n = sum;
        sum = countSum(n);
    }

    return false;
}

int main() {
    cout << isHappy(3);
}