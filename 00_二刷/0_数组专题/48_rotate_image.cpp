/* T48:旋转图像 https://leetcode-cn.com/problems/rotate-image/
 * 思路：先水平翻转，再沿对角线翻转
 * 方法：用翻转代替旋转(n*2^n)
 * */

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // 水平翻转
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n; j++)
            swap(matrix[i][j], matrix[n-i-1][j]);
    // 主对角线翻转
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            swap(matrix[i][j], matrix[j][i]);
    return;
}