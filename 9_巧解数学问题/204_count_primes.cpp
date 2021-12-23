/* leetcode T204:计数质数
 * 原题链接：https://leetcode-cn.com/problems/count-primes/
 * */


#include <iostream>
#include <vector>

using namespace std;

//int countPrimes(int n) {
//    if (n <= 2) return 0;
//    vector<bool> prime(n, true);
//    int count = n - 1;// 1和2不是质数--不是质数则count--
//    for (int i = 2; i <= n; i++) {
//        if (prime[i]) {
//            for (int j = i * 2; j <= n; j += i) {
//                if (prime[j]) {
//                    prime[j] = false;// j不是质数
//                    --count;
//                }
//            }
//        }
//    }
//    return count;
//}

int countPrimes(int n) {
    int count = n - 2;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                --count;
                break;
            }
        }
    }
    return count;
}
int main() {
    cout << countPrimes(5000000) << endl;
}