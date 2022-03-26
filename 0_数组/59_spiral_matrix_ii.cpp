/* leetcode T59:螺旋矩阵 II
 * 原题链接：https://leetcode-cn.com/problems/spiral-matrix-ii/
 * */

/* 方法一：模拟法
 *
 * 算法思想：参考https://www.programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html#%E6%80%9D%E8%B7%AF
 * 关键点：
 * 要统一循环的边界条件--左闭右开
 *
 * 复杂度分析：
 * 时间复杂度：O(n*n)，
 * 空间复杂度：O(1)。
 * */

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int startx = 0, starty = 0;// 每个圈/循环的其实位置
    int loop = n / 2;// 循环的圈数
    int mid = n / 2;// 矩阵的中间位置
    int count = 1;// 矩阵待填充的值 [1, n^2]
    int offset = 1;// 每循环一圈，每条边缩小的长度
    int i, j;// 定位矩阵位置

    while (loop--) {
        i = startx, j = starty;
        // 依次填充四条边
        // 上行
        for (; j < starty + n - offset; j++) {
            res[i][j] = count++;
        }
        // 右列
        // for (; i < ...)
        for (; i < startx + n - offset; i++) {
            res[i][j] = count++;
        }
        // 下行
        for (; j > starty; j--) {
            res[i][j] = count++;
        }
        // 左行
        for (;i > startx; i--) {
            res[i][j] = count++;
        }

        // 更新下一圈的起始位置
        startx++;
        starty++;

        // 更新offset--下一圈中每条边的长度
        offset += 2;
    }

    if (n % 2 != 0) {
        res[mid][mid] = count;
    }

    return res;
}