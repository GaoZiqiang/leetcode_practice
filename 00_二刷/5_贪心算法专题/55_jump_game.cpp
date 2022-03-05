/* T55:跳跃游戏 https://leetcode-cn.com/problems/jump-game/
 * 思路：https://leetcode-cn.com/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode-solution/
 * 每个位置可以到达的最远位置：rightmost = max(rightmost, i + nums[i]);
 * 只要每个i在rightmost的范围内，就说明该位置i可以安全到达
 * 方法：贪心算法O(n)
 * */

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int rightmost = 0;
    for (int i = 0; i < n; i++) {
        if (i <= rightmost) {
            rightmost = max(rightmost, i + nums[i]);
            if (rightmost >= n - 1) {
                return true;
            }
        }
    }
    return false;
}