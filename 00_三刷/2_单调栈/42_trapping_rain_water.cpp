/* T42:接雨水 https://leetcode-cn.com/problems/trapping-rain-water/
 *
 * 方法一：单调栈
 * 算法思想：
 * 使用一个单调递减栈，将递减的边界存进去，一旦发现当前的数字大于栈顶元素了，那么就有可能会有能装水的
 * 地方产生。
 * 此时我们当前的数字是右边界，我们从栈中至少需要有两个数字，才能形成一个坑槽，先取出的那个最小的数字，
 * 就是坑槽的最低点，再次取出的数字就是左边界，我们比较左右边界，取其中较小的值为装水的边界，然后此高度
 * 减去水槽最低点的高度，乘以左右边界间的距离就是装水量了。
 *
 * 关键点：
 * 1 stack栈中存的是height数组的下标 这一点和别的单调栈问题是相通的
 *
 * 时间复杂度：O(n)。
 * 空间复杂度：O(n)，stack栈空间。
 * */

int trap(vector<int>& height) {
    int n = height.size();
    stack<int> stack;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        while (!stack.empty() && height[stack.top()] < height[i]) {
            int bh = height[stack.top()];
            stack.pop();
            if (stack.empty()) break;// 最左边只有一个元素
            int left = stack.top(), right = i;// 确定左右边界
            int lh = height[left], rh = height[right];// 确定左右边界的高度
            int curWidth = right - left - 1;// 注意宽度curWidth的计算
            int curHeight = min(lh, rh) - bh;// 水柱的高度
            ans += curWidth * curHeight;// 计算面积
        }
        stack.push(i);
    }

    return ans;
}