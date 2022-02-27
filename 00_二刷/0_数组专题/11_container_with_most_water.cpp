/* T11:盛最多水的容器 https://leetcode-cn.com/problems/container-with-most-water/
 * 思路：https://app.yinxiang.com/Home.action?_sourcePage=kyeeqHe6-DniMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=Q1bMCpORWMw3yWPvuidLz-TPR6I9Jhx8&login=true&username=gaoziqianghi%40163.com#n=646720e8-79da-4663-aa13-c803e7636c60&s=s3&ses=4&sh=2&sds=2&
 * 方法：双指针法O(n)
 * */

int maxArea(vector<int>& height) {
    int maxArea = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
        int curArea = (right - left) * min(height[left], height[right]);
        maxArea = max(curArea, maxArea);
        if (height[left] < height[right]) {// 移动较短的
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}