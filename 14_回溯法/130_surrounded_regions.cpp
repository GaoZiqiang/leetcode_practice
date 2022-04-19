/* leetcode T130:被围绕的区域
 * 原题链接：https://leetcode-cn.com/problems/surrounded-regions/
 * */

/* 方法一：DFS递归
 *
 * 核心思想：从四周突破
 * 任何边界上的 O 都不会被填充为 X -->所有的不被包围的 O 都直接或间接与边界上的 O 相连。
 * -->
 * 对于每一个边界上的 O，我们以它为起点，标记所有与它直接或间接相连的字母 O
 * -->具体而言：
 * 当元素值为'X'或者已经标记过的'O'跳过
 * 未被标记过的'O'进行标记
 *
 * 复杂度分析：
 * 时间复杂度：O(m*n)，因为元素被标记过后就不会再被访问了，因此每个元素至多访问一次。
 * 空间复杂度：O(m*n)，递归所用栈空间，二维空间。
 * */

void dfs(vector<vector<char>>& board, int i, int j) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == '#') return;// 'X'或已经标记过'#'的'O'跳过
    board[i][j] = '#';// 非包围区域的'O'且未标记过的'O'

    dfs(board, i, j - 1);
    dfs(board, i, j + 1);
    dfs(board, i - 1, j);
    dfs(board, i + 1, j);

    return;
}

void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();

    // 从四周突入
    for (int i = 0; i < m; i++) {
        dfs(board, i, 0);
        dfs(board, i, n - 1);
    }

    for (int j = 0; j < n; j++) {
        dfs(board, 0, j);
        dfs(board, m - 1, j);
    }

    // 更新原矩阵
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '#') {
                board[i][j] = 'O';// 非包围区域的'O'
            } else if (board[i][j] == 'O') {
                board[i][j] = 'X';// 包围区域的'O'
            }
        }
    }

    return;
}