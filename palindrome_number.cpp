#include <vector>
#include <stdio.h>
#include <iostream>

#define MAXSIZE 20

using namespace std;

long * getDigits(long);
bool isPalindromeNumber(long * nums);

int main() {
//    int xs[] = {1,2,3,2,1};
    long xs = 123212;
    long * nums;
    nums = getDigits(xs);

    printf("nums[0]: %ld\n",*(nums+2));

    if (isPalindromeNumber(nums))
        printf("xs is\n");
    else
        printf("xs is not\n");
//    cout << "nums: " << nums << endl;
//    int i = 0;
//    while (nums) {
//        printf("nums: %ld\n",*nums);
//        nums += 1;
//    }

    delete [] nums;
}

long * getDigits(long xs) {
    int digits;
//    vector<long> nums;
//    long nums[MAXSIZE] = {1,2,2,3,3,3,3,3};
    long * nums = new long[MAXSIZE];// 开辟内存
    int i = 0;
    nums[i] = xs % 10;
    while (xs /= 10) {
        i++;
        digits++;
        nums[i] = xs % 10;
        printf("nums[i]: %ld\n",xs % 10);
//        nums.push_back(xs % 10);
//        nums.insert(xs % 10);
    }

    return nums;
}

bool isPalindromeNumber(long * nums) {
    int low = 0, high = 5;
    while (low <= high) {
        if (nums[low] != nums[high])
            break;
        low++;
        high--;
    }
    if (low > high)
        return true;
    if (low < high)
        return false;
}