/* T22:括号生成 https://leetcode-cn.com/problems/generate-parentheses/
 * 思路：https://app.yinxiang.com/Home.action?_sourcePage=kyeeqHe6-DniMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=Q1bMCpORWMw3yWPvuidLz-TPR6I9Jhx8&login=true&username=gaoziqianghi%40163.com#n=17deef15-5735-4894-971a-60cc0b0e1623&s=s3&t=9b8b7b13-7239-446d-8ad5-eddfabb8fa22&ses=4&sh=3&sds=5&
 * 方法：回溯O(n*2^n)
 * */

void dfs(int& n, vector<string>& res, int& l, int& r, string& str) {
    if (l == r && l == n) {
        res.push_back(str);// 符合则res.push_back
        return;
    }
    if (r > l) return;// 不符合则直接return

    // 横向循环--查看可能的遍历选项--‘(‘或者‘)’
    if (l < n) {
        str += '(';
        l++;
        dfs(n, res, l, r, str);
        l--;
        str.pop_back();
    }
    if (r < n) {
        str += ')';
        r++;
        dfs(n, res, l, r, str);
        r--;
        str.pop_back();
    }
    return;
}
vector<string> generateParenthesis(int n) {
    if (n == 0) {
        return {};
    }
    vector<string> res;
    string str;
    int l = 0, r = 0;
    dfs(n, res, l, r, str);
    return res;
}