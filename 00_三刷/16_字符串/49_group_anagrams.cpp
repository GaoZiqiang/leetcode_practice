/* T49:字母异位词分组 https://leetcode.cn/problems/group-anagrams/
 *
 * 方法一：基于排序
 *
 * 算法思想：
 * 字母异位词排序后的源单词是相同的，因此可以使用map进行存储
 *
 * 时间复杂度：O(n)。
 * 空间复杂度：O(nk)，n为字符串总量，k为最长的字符串的长度。
 * */


#include <bits/c++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    unordered_map<string, vector<string>> map;

    for (int i = 0; i < strs.size(); ++i) {
        string str = strs[i];
        string copyStr = str;
        sort(copyStr.begin(), copyStr.end());// 对各字母异位词进行排序
        map[copyStr].emplace_back(str);// 属于同一源单词的异位词置于同一vector中
    }

    vector<vector<string>> ans;
    for (auto& it = map.begin(); it != map.end(); ++it) {
        ans.emplace_back(it->second);
    }

    return ans;
}