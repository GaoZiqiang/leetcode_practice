// 统计有序数组中与目标元素相同的元素个数
// 参考：https://blog.csdn.net/weixin_44360742/article/details/113100103
// 思想：二分查找+线性查找
#include <vector>
#include <iostream>

using namespace std;

int same_num(vector<int>& nums, int target) {
    int n = nums.size();
    // 排序
    // sort(nums.begin(), nums.end());
    int low = 0, high = n - 1;
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (target == nums[mid]) {
            // mid在最左边
            if (mid - 1 >= 0 && nums[mid-1] != nums[mid]) {
                while(mid < n && nums[mid] == target) {
                    ans++;
                    mid++;
                }
                return ans;
            // mid在最右边
            } else if (mid + 1 < n && nums[mid+1] != nums[mid]) {
                while (mid >= 0 && nums[mid] == target) {
                    ans++;
                    mid--;
                }
                return ans;
            // mid在中间
            } else {
                // 往左边找
                while (mid >= 0 && nums[mid] == target) {
                    ans++;
                    mid--;
                }
                // 往右边找
                while (mid < n && nums[mid] == target) {
                    ans++;
                    mid++;
                }
                return ans;
            }
        } else if (target > nums[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1,2,3,3,4,4,4,5,6};
    int target = 0;
    cout << same_num(nums, target) << endl;
}