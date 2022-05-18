/* T45:跳跃游戏II https://leetcode.cn/problems/jump-game-ii/
 *
 * 方法一：贪心算法
 *
 * 算法思想：
 * 本题做一个转换-->以最小步数增加覆盖范围
 *
 * 核心：
 * 如果当前点i所能到达的最远距离curDistance不能到达终点
 * -->则遍历/寻找[i, i+curDistance]之间的能够到达最远距离nextDistance的点(设为j)
 * -->并跳转到该j+nextDistance处
 *
 * 时间复杂度：O(n)。
 * 空间复杂度：O(1)。
 * */

#include <vector>

using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;
    int curDistance = 0, nextDistance = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        nextDistance = max(i + nums[i], nextDistance);
        // 已经走完当前所能到达的最远距离curDistance
        if (i == curDistance) {
            // 如果此时已经到达终点-->break结束
            if (curDistance == n - 1) break;
            // 否则跳到[当前i, i+curDistance]之间的点(某个点j)所能到达的最远距离处(该点j作为i的下一跳)
            ans++;
            curDistance = nextDistance;
            if (nextDistance >= n - 1) break;// 下一跳已经能够到达终点-->结束
        }
    }

    return ans;
}