/* T17:电话号码的字母组合 https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 * 思路：https://app.yinxiang.com/Home.action?_sourcePage=kyeeqHe6-DniMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=Q1bMCpORWMw3yWPvuidLz-TPR6I9Jhx8&login=true&username=gaoziqianghi%40163.com#n=17deef15-5735-4894-971a-60cc0b0e1623&s=s3&ses=4&sh=2&sds=2&
 * 方法：双指针法O(n*2^n)
 * */

unordered_map<char, string> ss;

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) {
        return {};
    }
    getSS(ss);
    vector<string> res;
    string path;
    dfs(digits, 0, res, path);
    return res;
}

// 回溯
void dfs(string& digits, int start, vector<string>& res, string& path) {
    if (path.size() == digits.size()) {
        res.push_back(path);
        return;
    }

    char digit = digits[start];
    string s = ss[digit];

    for (int i = 0; i < s.size(); i++) {// i从0开始
        path += s[i];
        dfs(digits, start + 1, res, path);// start+1-->下一个数字
        path.pop_back();
    }
    return;
}

// 数字-字母匹配
void getSS(unordered_map<char, string>& ss) {
    ss.insert(std::make_pair('2', "abc"));
    ss.insert(std::make_pair('3', "def"));
    ss.insert(std::make_pair('4', "ghi"));
    ss.insert(std::make_pair('5', "jkl"));
    ss.insert(std::make_pair('6', "mno"));
    ss.insert(std::make_pair('7', "qprs"));
    ss.insert(std::make_pair('8', "tuv"));
    ss.insert(std::make_pair('9', "wxyz"));
    return;
}