/* leetcode T648:单词替换
 * 原题链接：https://leetcode-cn.com/problems/replace-words/
 * */

/* 方法一：前缀哈希
 *
 * 算法思想：参考https://leetcode-cn.com/problems/replace-words/solution/dan-ci-ti-huan-by-leetcode/
 *
 * 复杂度分析：
 * 时间复杂度：O(w1^2+w2^2+...+wn^2)，wi为第i个单词的长度。检查第i个单词的所有前缀花费时间w1^2+w2^2+...+wn^2。
 * 空间复杂度：O(n)，set。
 * */

#include <set>

using namespace std;

// 以' '分割原来string sentence
std::vector<std::string> stringSplit(const std::string& str, char delim) {
    std::stringstream ss(str);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

string replaceWords(vector<string>& dictionary, string sentence) {
    set<string> dictset;
    string ans = "";

    // 将string sentence转换为vector<string>
    vector<string> strsentence = stringSplit(sentence, '  ');

    // 将dictionary中的词根存入set
    for (string& dict : dictionary) dictset.insert(dict);

    // 判断每个单次的前缀是否位于dictset
    for (string& word : strsentence) {
        string prefix = "";
        for (int i = 1; i <= word.size(); ++i) {
            prefix = word.substr(0, i);
            if (dictset.find(prefix) != dictset.end()) break;
        }
        if (ans.size() > 0) ans += " ";
        ans += prefix;
    }

    return ans;
}