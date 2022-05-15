/* T55:跳跃游戏 https://leetcode-cn.com/problems/jump-game/
 * 思路：https://leetcode-cn.com/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode-solution/
 * 每个位置可以到达的最远位置：rightmost = max(rightmost, i + nums[i]);
 * 只要每个i在rightmost的范围内，就说明该位置i可以安全到达
 * 方法：贪心算法O(n)
 *
 * 该方法的核心：参考https://www.programmercarl.com/0055.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8F.html#%E6%80%9D%E8%B7%AF
 * 将具体的跳跃步数转换为跳跃范围，只要最终的跳跃范围能够覆盖终点即可。
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

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int cover = 0;

    for (int i = 0; i <= cover; i++) {
        cover = max(i + nums[i], cover);
        if (cover >= n - 1) return true;
    }

    return false;
}