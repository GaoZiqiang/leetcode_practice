/* T131:分割回文串 https://leetcode.cn/problems/palindrome-partitioning/
 *
 * 方法一：递归+回溯
 *
 * 算法思想：
 * 仍然借助递归+回溯思想，只不过，本题是截取[start,i]之间的子串
 * 然后对子串进行判断
 *  若满足回文定义，则入path
 *  否则continue(因为[start,i]这段已经不满足回文了，再继续dfs下一层就没必要了)
 *
 * 关键点：
 * 若[start,i]不满足回文定义-->continue
 *
 * 时间复杂度：O(Cn,k * k)，共Cn,k种组合，每种组合需要O(k)的时间复杂度。
 * 空间复杂度：O(n)，递归的层数。
 * */


#include <string>

using namespace std;

bool isPalindrome(string& s, int start, int end) {
    for (int i = start, j = end; i <= j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}

void dfs(string& s, int start, vector<string>& path, vector<vector<string>>& ans) {
    if (start >= s.size()) {
        ans.push_back(path);
        return;
    }

    for (int i = start; i < s.size(); i++) {
        if (isPalindrome(s, start, i))
            path.push_back(s.substr(start, i-start+1));
        else
            continue;
        dfs(s, i+1, path, ans);
        path.pop_back();
    }
}

vector<vector<string>> partition(string s) {
    vector<string> path;
    vector<vector<string>> ans;

    dfs(s, 0, path, ans);

    return ans;
}